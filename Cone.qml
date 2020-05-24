import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Extras 2.12


Entity {
    property alias pos: transform.translation
    id: cone


        TextureLoader {
            id: texture
            source: "qrc:/Objects/Textures/cone/orange_stripes.jpg"
        }


        Mesh {
            id: mesh
            source: "qrc:/Objects/Cone.obj"
        }

        DiffuseSpecularMaterial {
            id: diffuseMaterial

            diffuse: texture
            specular: texture
            shininess: 0.6
        }

        Transform {
            id: transform
            scale: 0.07
        }

    components: [ transform, mesh, diffuseMaterial ]
}
