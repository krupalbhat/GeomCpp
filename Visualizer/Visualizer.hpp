#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include "../Core/Point.hpp"
#include "./ArialFontDataEmbed.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>

namespace GeomCPP {

class Visualizer {
private:
  sf::RenderWindow window;
  std::vector<sf::CircleShape> points;
  std::vector<sf::VertexArray> lines;
  sf::Font font;
  sf::Text mousePositionText;
  int width, height, gridSize;

public:
  Visualizer(int w = 1000, int h = 800, int grid_size = 50)
      : window(sf::VideoMode(w, h), "GeomCPP Visualization"), width(w),
        height(h), gridSize(grid_size) {

    if (!font.loadFromMemory(Arial_ttf, Arial_ttf_len)) {
      std::cerr << "Failed to load embedded font!\n";
      throw std::runtime_error("Could not load font from memory!");
    }

    mousePositionText.setFont(font);
    mousePositionText.setCharacterSize(16);
    mousePositionText.setFillColor(sf::Color::Black);
    mousePositionText.setPosition(10, 10);
  }

  template <typename T, std::size_t Dim>
  void addPoint(const Point<T, Dim> &point) {
    auto coords = point.get_coordinates();
    if constexpr (Dim >= 2) {
      sf::CircleShape shape(5);
      shape.setFillColor(sf::Color::Red);
      shape.setPosition(static_cast<float>(coords[0]) - 2.5f,  // Center correction
                        static_cast<float>(coords[1]) - 2.5f);
      points.push_back(shape);
    }
  }

  template <typename T, std::size_t Dim>
  void addLine(const Point<T, Dim> &p1, const Point<T, Dim> &p2) {
    auto coords1 = p1.get_coordinates();
    auto coords2 = p2.get_coordinates();

    if constexpr (Dim >= 2) {
      sf::VertexArray line(sf::Lines, 2);
      line[0].position = sf::Vector2f(static_cast<float>(coords1[0]),
                                      static_cast<float>(coords1[1]));
      line[0].color = sf::Color::Blue;
      line[1].position = sf::Vector2f(static_cast<float>(coords2[0]),
                                      static_cast<float>(coords2[1]));
      line[1].color = sf::Color::Blue;
      lines.push_back(line);
    }
  }

  void drawGrid(sf::RenderWindow &window) {
    sf::VertexArray lines(sf::Lines);

    for (int x = 0; x < width; x += gridSize) {
      lines.append(sf::Vertex(sf::Vector2f(x, 0), sf::Color(200, 200, 200)));
      lines.append(
          sf::Vertex(sf::Vector2f(x, height), sf::Color(200, 200, 200)));
    }

    for (int y = 0; y < height; y += gridSize) {
      lines.append(sf::Vertex(sf::Vector2f(0, y), sf::Color(200, 200, 200)));
      lines.append(
          sf::Vertex(sf::Vector2f(width, y), sf::Color(200, 200, 200)));
    }

    window.draw(lines);
  }

  void run() {
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
      }

      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      std::stringstream ss;
      ss << "Mouse: (" << mousePos.x << ", " << mousePos.y << ")";
      mousePositionText.setString(ss.str());

      window.clear(sf::Color::White);
      drawGrid(window);

      for (const auto &line : lines)
        window.draw(line);

      for (const auto &point : points)
        window.draw(point);

      window.draw(mousePositionText);
      window.display();
    }
  }
};

} // namespace GeomCPP

#endif // VISUALIZATION_HPP
