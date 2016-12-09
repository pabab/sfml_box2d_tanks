#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Graphics/VertexArray.hpp>

class fPhysicsDebugDraw: public b2Draw{
public:
    fPhysicsDebugDraw();
    void DrawPolygon (const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);
    void DrawSolidPolygon (const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);
    void DrawCircle (const b2Vec2 &center, float32 radius, const b2Color &color);
    void DrawSolidCircle (const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color);
    void DrawSegment (const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color);
    void DrawTransform (const b2Transform &xf);
    const std::vector<sf::VertexArray> &getVertexArrays() const;
    void clearVertexArrays();

private:
    std::vector<sf::VertexArray> vertexArrays;
    unsigned char alpha;
};
