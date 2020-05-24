import QtQuick 2.12 as QQ2
import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Input 2.12
import Qt3D.Logic 2.12
import Qt3D.Extras 2.12

Entity {
    id: sceneRoot
    property int hightGround: 0 // y is up


    Entity {
        components: [
            DirectionalLight {
                color: Qt.rgba(1, 1, 1)
                intensity: 0.5
                worldDirection: Qt.vector3d(0.6, -1,-0.6)
            }
        ]
    }

    Ground{
        id: ground
//        Environment.pos: Qt.vector3d(0,0,0)

    }

    Car{

    }

    Acceltrack{

    }
}
