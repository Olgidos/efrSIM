import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Extras 2.12
import QtQuick 2.12

Entity {
    id: acceltrack

     Component.onCompleted : {
         var coneComponent = Qt.createComponent("Cone.qml")
         for(var i = 0; i < 16; i++) {
             var cone = coneComponent.createObject(acceltrack);
             cone.pos = Qt.vector3d(15 + i*5,0,-2.5);

             cone = coneComponent.createObject(acceltrack);
             cone.pos = Qt.vector3d(15 + i *5,0,2.5);
         }
     }
}
