import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Extras 2.12

Entity {
    property alias pos: transform
    components: [

//        TextureLoader {
//            id: texture
//            source: "qrc:/Viewer/Objects/Textures/cone/orange_stripes.jpg"
//        }


        Mesh {
            id: mesh
            source: "qrc:/Objects/carMain.STL"
        },

        DiffuseSpecularMaterial {
            id: diffuseMaterial

            diffuse: "orange"
            shininess: 0.2
        },

        Transform {
            id: transform
            scale: 1
        }
    ]
}
