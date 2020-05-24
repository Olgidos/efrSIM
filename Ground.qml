import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Extras 2.12


Entity {
    property int sizeGround: 100
    property int heightGround: 1
    property alias position: transform.translation

    id: ground

    DiffuseSpecularMaterial {
        id: diffuseMaterial
        //ambient: TextureLoader { source: "qrc:/Viewer/Objects/Textures/soil/soil_bmp.jpg"; }
//        diffuse: TextureLoader { source: "qrc:/Viewer/Objects/Textures/Marble_01/Marble_01_1K_Base_Color.png"; }
       // specular: TextureLoader { source: "qrc:/Viewer/Objects/Textures/Marble_01/Marble_01_1K_Roughness.png"; }
//        normal: TextureLoader { source: "qrc:/Viewer/Objects/Textures/Marble_01/Marble_01_1K_Normal.png"; }
        textureScale: 1
        shininess: 0.5
        //alphaBlending: true
    }


    TexturedMetalRoughMaterial {
        id: matSphere1Material
        baseColor:  TextureLoader {
            source: "qrc:/Objects/Textures/fascade/Facade01_col.jpg"
            format: Texture.SRGB8_Alpha8
            generateMipMaps: true
        }
        metalness: TextureLoader { source: "qrc:/Objects/Textures/fascade/Facade01_met.jpg"; generateMipMaps: true }
        roughness: TextureLoader { source: "qrc:/Objects/Textures/fascade/Facade01_rgh.jpg"; generateMipMaps: true}
        normal: TextureLoader { source: "qrc:/Objects/Textures/fascade/Facade01_nrm.jpg"; generateMipMaps: true }
        ambientOcclusion: TextureLoader { source: "qrc:/Objects/Textures/no-ao.png" }
        textureScale:  8
    }



     CuboidMesh {
         id: mesh
    }

    Transform {
        id: transform
        translation:    Qt.vector3d(50,-0.06,0)
        scale3D:        Qt.vector3d(100,0.1,10)

     }

    components: [ transform, mesh, matSphere1Material ]
}
