import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Extras 2.12

Entity{

   property alias pos: transform

    components: [
        DiffuseSpecularMaterial {
            ambient: "orange"
            shininess: 0.5
        },
        
        Mesh{
            source: "qrc:/Objects/wheelEFR.STL"
        },
        
        Transform {
            id: transform
            scale: 1
//            matrix: {
//                        var m = Qt.matrix4x4();
//                        m.rotation = Qt.quaternion(WheelFLQuaternionScalar.value,WheelFLQuaternionX.value,WheelFLQuaternionY.value,WheelFLQuaternionZ.value);
//                        //m.translate(Qt.vector3d(0, 1, WheelFLPosX.value));
//                        return m;
//                    }
        }
    ]
}
