#include "Components.h"
#include <memory>
#include <string>

class Entity
{
private:
    friend class EntityManager;

    bool m_active = true;
    size_t m_id = 0;
    std::string m_tag = "default";
    // constructor and destructure
    Entity(const size_t id, const std::string& tag);

public:
    // component pointers
    std::share_ptr<CTransform> cTransform;
    std::share_ptr<CShape> cShape;
    std::share_ptr<CCollision> cCollision;
    std::share_ptr<CInput> cInput;
    std::share_ptr<CScore> cScore;
    std::share_ptr<CLifespan> cLifespan;

    bool isActive() const;
    const std::string & tag() const;
    const size_t id() const;
    void destroy();
};

