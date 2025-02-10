#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <filesystem>
#include "../Core/Point.hpp" // Include your GeomCPP Point class

namespace fs = std::filesystem;

namespace GeomCPP
{
    class Visualizer
    {
    private:
        sf::RenderWindow window;
        std::vector<sf::CircleShape> points;
        sf::Font font;
        sf::Text mousePositionText;

        int width, height, gridSize;

    public:
        Visualizer(int w = 1000, int h = 800, int grid_size = 50)
            : window(sf::VideoMode(w, h), "GeomCPP Visualization"), width(w), height(h), gridSize(grid_size)
        {
            std::string fontPath = fs::current_path().string() + "/GeomCpp/Visualizer/Arial.ttf";
            if (!font.loadFromFile(fontPath))
            {
                throw std::runtime_error("Could not load font file!");
            }

            mousePositionText.setFont(font);
            mousePositionText.setCharacterSize(16);
            mousePositionText.setFillColor(sf::Color::Black);
            mousePositionText.setPosition(10, 10);
        }

        template <typename T, std::size_t Dim>
        void addPoint(const Point<T, Dim> &point)
        {
            auto coords = point.get_coordinates(); 
            if constexpr (Dim >= 2)
            {
                sf::CircleShape shape(5);
                shape.setFillColor(sf::Color::Red);
                shape.setPosition(static_cast<float>(coords[0]), static_cast<float>(coords[1]));
                points.push_back(shape);
            }
        }

        void drawGrid(sf::RenderWindow &window)
        {
            sf::VertexArray lines(sf::Lines);

            for (int x = 0; x < width; x += gridSize)
            {
                lines.append(sf::Vertex(sf::Vector2f(x, 0), sf::Color(200, 200, 200))); // Light gray
                lines.append(sf::Vertex(sf::Vector2f(x, height), sf::Color(200, 200, 200)));
            }

            // Draw horizontal lines
            for (int y = 0; y < height; y += gridSize)
            {
                lines.append(sf::Vertex(sf::Vector2f(0, y), sf::Color(200, 200, 200)));
                lines.append(sf::Vertex(sf::Vector2f(width, y), sf::Color(200, 200, 200)));
            }

            window.draw(lines);
        }

        // Run visualization loop
        void run()
        {
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                // Get mouse position
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                std::stringstream ss;
                ss << "Mouse: (" << mousePos.x << ", " << mousePos.y << ")";
                mousePositionText.setString(ss.str());

                // Clear window
                window.clear(sf::Color::White);

                // Draw grid
                drawGrid(window);

                // Draw points
                for (const auto &point : points)
                    window.draw(point);

                // Draw mouse position text
                window.draw(mousePositionText);

                // Display everything
                window.display();
            }
        }
    };
}

#endif // VISUALIZATION_HPP
