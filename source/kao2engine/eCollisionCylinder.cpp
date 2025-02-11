#include <kao2engine/eCollisionCylinder.h>
#include <kao2ar/Archive.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eCollisionCylinder interface
    // <kao2.00599300> (constructor)
    // <kao2.00599370> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_COLLISIONCYLINDER_TYPEINFO
    (
        E_COLLISIONCYLINDER_ID,
        "eCollisionCylinder",
        &E_COLLISIONPRIMITIVE_TYPEINFO,
        []() -> eObject*
        {
            return new eCollisionCylinder;
        }
    );

    TypeInfo* eCollisionCylinder::getType()
    {
        return &E_COLLISIONCYLINDER_TYPEINFO;
    }

    eCollisionCylinder::eCollisionCylinder()
    : eCollisionPrimitive()
    {}

    eCollisionCylinder::~eCollisionCylinder() {}

}
