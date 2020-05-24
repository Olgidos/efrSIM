import QtQuick 2.0 as QQ2
import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Input 2.12
import Qt3D.Logic 2.12
import Qt3D.Extras 2.12

Entity {
    id: sceneRoot
    property vector3d defaultUp: Qt.vector3d(0, 1, 0)
    property vector3d defaultCameraPosition: Qt.vector3d(5,1,-1)
    property vector3d defaultViewCenter: Qt.vector3d(100,0,0)

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                clearColor: "black"
                camera: Camera {
                    id: camera
                    projectionType: CameraLens.PerspectiveProjection
                    fieldOfView: 45
                    nearPlane : 0.1
                    farPlane : 1000.0
                    position: defaultCameraPosition
                    upVector: defaultUp
                    viewCenter: defaultViewCenter
                }
            }
            pickingSettings.pickMethod: PickingSettings.TrianglePicking
        },
        InputSettings {}
    ]

    FirstPersonCameraController { camera: camera }

    Scene {
    }
}
