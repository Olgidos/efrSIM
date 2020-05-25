import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Extras 2.12

Entity {

    Wheel{
        id: wheelfl
        pos.translation.x:  r__Wheel_x_1.value
        pos.translation.y:  r__Wheel_z_1.value
        pos.translation.z:  -r__Wheel_y_1.value

        pos.rotationX: rot_y_Wheel_1.value
        pos.rotationY: rot_z_Wheel_1.value
        pos.rotationZ: rot_x_Wheel_1.value
    }

    Wheel{
        id: wheelfr
        pos.translation.x:  r__Wheel_x_4.value
        pos.translation.y:  r__Wheel_z_4.value
        pos.translation.z:  -r__Wheel_y_4.value

        pos.rotationX: rot_y_Wheel_4.value
        pos.rotationY: rot_z_Wheel_4.value
        pos.rotationZ: rot_x_Wheel_4.value
    }

    Wheel{
        id: wheelrl
        pos.translation.x:  r__Wheel_x_2.value
        pos.translation.y:  r__Wheel_z_2.value
        pos.translation.z:  -r__Wheel_y_2.value

        pos.rotationX: rot_y_Wheel_2.value
        pos.rotationY: rot_z_Wheel_2.value
        pos.rotationZ: rot_x_Wheel_2.value
    }

    Wheel{
        pos.translation.x:  r__Wheel_x_3.value
        pos.translation.y:  r__Wheel_z_3.value
        pos.translation.z:  -r__Wheel_y_3.value

        pos.rotationX: rot_y_Wheel_3.value
        pos.rotationY: rot_z_Wheel_3.value
        pos.rotationZ: rot_x_Wheel_3.value
    }


    CarMain{
        pos.translation.x:  r__Mainbody_x.value
        pos.translation.y:  r__Mainbody_z.value
        pos.translation.z:  -r__Mainbody_y.value

        pos.rotationX: rot_Mainbody_z.value
        pos.rotationY: rot_Mainbody_x.value
        pos.rotationZ: -rot_Mainbody_y.value

    }
}
