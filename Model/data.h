#ifndef VALUES_H
#define VALUES_H
#include <Values/parameter.h>
#include <Values/value.h>
#include <cstddef>
#include <memory>
#include <iostream>
#include <Qt3DCore>


class Solid;

extern void addProperty(const QString, QObject *obj);

class Data
{
   public:

   Data():
     //Initialisation of Values BEGINN

     //General
       initTimestep               { -1.0, "initTimestep", "s", "General"},
       timestep                   { 0.00005, "Timestep_Δt", "s", "General"},
       displayTime                { initTimestep.val(), "DisplayTime", "s", "General"},
       totalSimulationTime        { 0.0, "TotalSimulationTime", "s", "General"},
       playbackSpeed              { 1.0, "PlaybackSpeed", "", "General"},
       totalCalculationTime       { 0.0, "TotalCalculationTime", "ms", "General"},
       chartZoom                  { 0.0, "ChartZoom", "", "General"},
       calculationTimePerStep     { "CalculationTimePerStep", "ms" , "General", displayTime},

     //Simulation Environment
       g                          { 9.81, "Gravitation", "m/(s^2)", "Simulation Environment"},

     //Joints

       wheelSusRealc              { 17000, "c__RealSuspension_z", "N/m", "Joint Suspension"},
       wheelSusReald              { 100, "d__RealSuspension_z", "kg/s", "Joint Suspension"},

     //WheelFL - SuspensionFL
       wheelSusFL_sx              { 0.799, "s__Suspension_x_1", "m", "Joint Suspension 1 (FL)"},
       wheelSusFL_sy              { 0.130, "s__Suspension_y_1", "m", "Joint Suspension 1 (FL)"},
       wheelSusFL_sz              { 0.160, "s__Suspension_z_1", "m", "Joint Suspension 1 (FL)"},

       wheelSusFLMass             { 1.83, "m__Suspension_1", "kg", "Joint Suspension 1 (FL)"},
       wheelSusFLEnabled          { 1.0, "SuspensionEnabled_1", " ", "Joint Suspension 1 (FL)"},

       wheelSusFLForceX           { "F__Suspension_x_1", "N", "Joint Suspension 1 (FL)", displayTime},
       wheelSusFLForceY           { "F__Suspension_y_1", "N", "Joint Suspension 1 (FL)", displayTime},
       wheelSusFLForceZ           { "F__Suspension_z_1", "N", "Joint Suspension 1 (FL)", displayTime},

       wheelSusFLTorqueX          { "M__Suspension_x_1", "Nm", "Joint Suspension 1 (FL)", displayTime},
       wheelSusFLTorqueY          { "M__Suspension_y_1", "Nm", "Joint Suspension 1 (FL)", displayTime},
       wheelSusFLTorqueZ          { "M__Suspension_z_1", "Nm", "Joint Suspension 1 (FL)", displayTime},


     //WheelFR - SuspensionFR
       wheelSusFR_sx              { 0.799, "s__Suspension_x_4", "m", "Joint Suspension 4 (FR)"},
       wheelSusFR_sy              { -0.130, "s__Suspension_y_4", "m", "Joint Suspension 4 (FR)"},
       wheelSusFR_sz              { 0.160, "s__Suspension_z_4", "m", "Joint Suspension 4 (FR)"},

       wheelSusFRMass             { 1.83, "m__Suspension_4", "kg", "Joint Suspension 4 (FR)"},
       wheelSusFREnabled          { 1.0, "SuspensionEnabled_4", " ", "Joint Suspension 4 (FR)"},

       wheelSusFRForceX           { "F__Suspension_x_4", "N", "Joint Suspension 4 (FR)", displayTime},
       wheelSusFRForceY           { "F__Suspension_y_4", "N", "Joint Suspension 4 (FR)", displayTime},
       wheelSusFRForceZ           { "F__Suspension_z_4", "N", "Joint Suspension 4 (FR)", displayTime},

       wheelSusFRTorqueX          { "M__Suspension_x_4", "Nm", "Joint Suspension 4 (FR)", displayTime},
       wheelSusFRTorqueY          { "M__Suspension_y_4", "Nm", "Joint Suspension 4 (FR)", displayTime},
       wheelSusFRTorqueZ          { "M__Suspension_z_4", "Nm", "Joint Suspension 4 (FR)", displayTime},

     //WheelRL - SuspensionRL
       wheelSusRL_sx              { -0.763, "s__Suspension_x_2", "m", "Joint Suspension 2 (RL)"},
       wheelSusRL_sy              { 0.130, "s__Suspension_y_2", "m", "Joint Suspension 2 (RL)"},
       wheelSusRL_sz              { 0.160, "s__Suspension_z_2", "m", "Joint Suspension 2 (RL)"},

       wheelSusRLMass             { 1.78, "m_Suspension_2", "kg", "Joint Suspension 2 (RL)"},
       wheelSusRLEnabled          { 1.0, "SuspensionEnabled_2", " ", "Joint Suspension 2 (RL)"},

       wheelSusRLForceX           { "F__Suspension_x_2", "N", "Joint Suspension 2 (RL)", displayTime},
       wheelSusRLForceY           { "F__Suspension_y_2", "N", "Joint Suspension 2 (RL)", displayTime},
       wheelSusRLForceZ           { "F__Suspension_z_2", "N", "Joint Suspension 2 (RL)", displayTime},

       wheelSusRLTorqueX          { "M__Suspension_x_2", "Nm", "Joint Suspension 2 (RL)", displayTime},
       wheelSusRLTorqueY          { "M__Suspension_y_2", "Nm", "Joint Suspension 2 (RL)", displayTime},
       wheelSusRLTorqueZ          { "M__Suspension_z_2", "Nm", "Joint Suspension 2 (RL)", displayTime},

     //WheelRR - SuspensionRR
       wheelSusRR_sx              { -0.763, "s__Suspension_x_3", "m", "Joint Suspension 3 (RR)"},
       wheelSusRR_sy              { -0.130, "s__Suspension_y_3", "m", "Joint Suspension 3 (RR)"},
       wheelSusRR_sz              { 0.160, "s__Suspension_z_3", "m", "Joint Suspension 3 (RR)"},

       wheelSusRRMass             { 1.78, "m__Suspension_3", "kg", "Joint Suspension 3 (RR)"},
       wheelSusRREnabled          { 1.0, "SuspensionEnabled_3", " ", "Joint Suspension 3 (RR)"},

       wheelSusRRForceX           { "F__Suspension_x_3", "N", "Joint Suspension 3 (RR)", displayTime},
       wheelSusRRForceY           { "F__Suspension_y_3", "N", "Joint Suspension 3 (RR)", displayTime},
       wheelSusRRForceZ           { "F__Suspension_z_3", "N", "Joint Suspension 3 (RR)", displayTime},

       wheelSusRRTorqueX          { "M__Suspension_x_3", "Nm", "Joint Suspension 3 (RR)", displayTime},
       wheelSusRRTorqueY          { "M__Suspension_y_3", "Nm", "Joint Suspension 3 (RR)", displayTime},
       wheelSusRRTorqueZ          { "M__Suspension_z_3", "Nm", "Joint Suspension 3 (RR)", displayTime},


       //Motors
       torqueMotorFL              { "M__Motor_1", "Nm", "Motors", displayTime},
       powerMotorFL               { "P__Motor_1", "W", "Motors", displayTime},
       torqueMotorEnabledFL       { 1.0, "MotorEnabled_1", " ", "Motors"},
       torqueMotorMaxFL           { 350.0, "M__MotorMax_1", "Nm", "Motors"},
       powerMotorMaxFL            { 17000.0, "P__MotorMax_1", "W", "Motors"},
       torqueMotorFR              { "M__Motor_4", "N", "Motors", displayTime},
       powerMotorFR               { "P__Motor_4", "W", "Motors", displayTime},
       torqueMotorEnabledFR       { 1.0, "MotorEnabled_4", " ", "Motors"},
       torqueMotorMaxFR           { 350.0, "M__MotorMax_4", "Nm", "Motors"},
       powerMotorMaxFR            { 17000.0, "P__MotorMax_4", "W", "Motors"},
       torqueMotorRL              { "M__Motor_2", "N", "Motors", displayTime},
       powerMotorRL               { "P__Motor_2", "W", "Motors", displayTime},
       torqueMotorEnabledRL       { 1.0, "MotorEnabled_2", " ", "Motors"},
       torqueMotorMaxRL           { 350.0, "M__MotorMax_2", "Nm", "Motors"},
       powerMotorMaxRL            { 19000.0, "P__MotorMax_2", "W", "Motors"},
       torqueMotorRR              { "M__Motor_3", "N", "Motors", displayTime},
       powerMotorRR               { "P__Motor_3", "W", "Motors", displayTime},
       torqueMotorEnabledRR       { 1.0, "MotorEnabled_3", "", "Motors"},
       torqueMotorMaxRR           { 350.0, "M__MotorMax_3", "Nm", "Motors"},
       powerMotorMaxRR            { 19000.0, "P__MotorMax_3", "W", "Motors"},

       //MotorController
       MotorC_keff                { 0.15, "κ__keff", " ", "Motor Controller"},
       motorC_Kp                  { 1000.0, "K__p", " ", "Motor Controller"},
       motorC_Ki                  { 100.0, "K__i", " ", "Motor Controller"},
       motorC_eimax               { 1000.0, "e__imax", " ", "Motor Controller"},
       motorC_eimin               { -1000.0, "e__imin", " ", "Motor Controller"},
       motorC_Kd                  { 0.2, "K__d", " ", "Motor Controller"},

       motorCFL_e                 { "e__1", " ", "Motor Controller", displayTime},
       motorCFR_e                 { "e__4", " ", "Motor Controller", displayTime},
       motorCRL_e                 { "e__2", " ", "Motor Controller", displayTime},
       motorCRR_e                 { "e__3", " ", "Motor Controller", displayTime},

     //Wheel Front Left
       wheelFL_sx                 { 0.804, "s__Wheel_x_1", "m", "Solid Wheel 1 (FL)"},
       wheelFL_sy                 { 0.600, "s__Wheel_y_1", "m", "Solid Wheel 1 (FL)"},
       wheelFL_sz                 { 0.05, "s__Wheel_z_1", "m", "Solid Wheel 1 (FL)"},

       wheelFL_mass               { "m__Wheel_1", "kg", "Solid Wheel 1 (FL)", displayTime},
       wheelFL_MOIX               { "J__Wheel_x_1", "kg*m^2*°", "Solid Wheel 1 (FL)", displayTime},
       wheelFL_MOIY               { "J__Wheel_y_1", "kg*m^2*°", "Solid Wheel 1 (FL)", displayTime},
       wheelFL_MOIZ               { "J__Wheel_z_1", "kg*m^2*°", "Solid Wheel 1 (FL)", displayTime},

       wheelFLMassRim             { 1.45, "m__Rim_1", "kg", "Solid Wheel 1 (FL)"},
       wheelFLMassTyre            { 3.95, "m__Tyre_1", "kg", "Solid Wheel 1 (FL)"},
       wheelFLMassMotorAssembly   { 7.2, "m__Assembly_1", "kg", "Solid Wheel 1 (FL)"},

       wheelFL_JTyreX             { 0.116, "J__Tyre_x_1", "kg*m^2", "Solid Wheel 1 (FL)"},
       wheelFL_JTyreY             { 0.189, "J__Tyre_y_1", "kg*m^2", "Solid Wheel 1 (FL)"},
       wheelFL_JTyreZ             { 0.116, "J__Tyre_z_1", "kg*m^2", "Solid Wheel 1 (FL)"},
       wheelFL_JRimX              { 0.022, "J__Rim_x_1", "kg*m^2", "Solid Wheel 1 (FL)"},
       wheelFL_JRimY              { 0.035, "J__Rim_y_1", "kg*m^2", "Solid Wheel 1 (FL)"},
       wheelFL_JRimZ              { 0.022, "J__Rim_z_1", "kg*m^2", "Solid Wheel 1 (FL)"},
       wheelFL_JRotorTransmissionX{ 0.001, "J__RotorTransmi_x_1", "kg*m^2", "Solid Wheel 1 (FL)"},
       wheelFL_JRotorTransmissionY{ 0.004, "J__RotorTransmi_y_1", "kg*m^2", "Solid Wheel 1 (FL)"},
       wheelFL_JRotorTransmissionZ{ 0.001, "J__RotorTransmi_z_1", "kg*m^2", "Solid Wheel 1 (FL)"},

       wheelFL_dMotorAssemblyX    { 0.00, "l__Assembly_x_1", "m","Solid Wheel 1 (FL)"},
       wheelFL_dMotorAssemblyY    { -0.02, "l__Assembly_y_1", "m", "Solid Wheel 1 (FL)"},
       wheelFL_dMotorAssemblyZ    { 0.02, "l__Assembly_z_1", "m", "Solid Wheel 1 (FL)"},

       wheelFLPosX                { "r__Wheel_x_1", "m", "Solid Wheel 1 (FL)", displayTime},
       wheelFLPosY                { "r__Wheel_y_1", "m", "Solid Wheel 1 (FL)", displayTime},
       wheelFLPosZ                { "r__Wheel_z_1", "m", "Solid Wheel 1 (FL)", displayTime},

       wheelFLVeloX               { "v__Wheel_x_1", "m/s", "Solid Wheel 1 (FL)", displayTime},
       wheelFLVeloY               { "v__Wheel_y_1", "m/s", "Solid Wheel 1 (FL)", displayTime},
       wheelFLVeloZ               { "v__Wheel_z_1", "m/s", "Solid Wheel 1 (FL)", displayTime},

       wheelFLAccelX              { "a__Wheel_x_1", "m/(s^2)", "Solid Wheel 1 (FL)", displayTime},
       wheelFLAccelY              { "a__Wheel_y_1", "m/(s^2)", "Solid Wheel 1 (FL)", displayTime},
       WheelFLAccelZ              { "a__Wheel_z_1", "m/(s^2)", "Solid Wheel 1 (FL)", displayTime},

       wheelFLAngularVeloX        { "rotVelo_x_Wheel_1", "°/s", "Solid Wheel 1 (FL)", displayTime},
       wheelFLAngularVeloY        { "rotVelo_y_Wheel_1", "°/s", "Solid Wheel 1 (FL)", displayTime},
       wheelFLAngularVeloZ        { "rotVelo_z_Wheel_1", "°/s", "Solid Wheel 1 (FL)", displayTime},

       wheelFLAngularAccelX       { "rotAccel_x_Wheel_1", "°/(s^2)", "Solid Wheel 1 (FL)", displayTime},
       wheelFLAngularAccelY       { "rotAccel_y_Wheel_1", "°/(s^2)", "Solid Wheel 1 (FL)", displayTime},
       wheelFLAngularAccelZ       { "rotAccel_z_Wheel_1", "°/(s^2)", "Solid Wheel 1 (FL)", displayTime},

       wheelFLEulerX              { "rot_x_Wheel_1", "°", "Solid Wheel 1 (FL)", displayTime},
       wheelFLEulerY              { "rot_y_Wheel_1", "°", "Solid Wheel 1 (FL)", displayTime},
       wheelFLEulerZ              { "rot_z_Wheel_1", "°", "Solid Wheel 1 (FL)", displayTime},

       wheelFL_Fz                 { "F__MFT_z_1", "N", "Solid Wheel 1 (FL)", displayTime},
       wheelFL_Fx                 { "F__MFT_x_1", "N", "Solid Wheel 1 (FL)", displayTime},
       wheelFL_k                  { "k__1", " ", "Solid Wheel 1 (FL)", displayTime},
       wheelFL_ux                 { "u__x_1", " ", "Solid Wheel 1 (FL)", displayTime},
       wheelFLMrollingResistanceY { "M__MFT_y_1", "Nm", "Solid Wheel 1 (FL)", displayTime},
       wheelFLMoverturningCoupleX { "M__MFT_x_1", "Nm", "Solid Wheel 1 (FL)", displayTime},

       wheelFLDisplacementWheelToBody {"WheelFL_DisplacementWheelToBody", "mm", "Solid Wheel 1 (FL)", displayTime},

     //Wheel Front Right
       wheelFR_sx                 { 0.804, "s__Wheel_x_4", "m", "Solid Wheel 4 (FR)"}, //799
       wheelFR_sy                 { -0.6, "s__Wheel_y_4", "m", "Solid Wheel 4 (FR)"},
       wheelFR_sz                 { 0.05, "s__Wheel_z_4", "m", "Solid Wheel 4 (FR)"},

       wheelFR_mass               { "m__Wheel_4", "kg", "Solid Wheel 4 (FR)", displayTime},
       wheelFR_MOIX               { "J__Wheel_x_4", "kg*m^2*°", "Solid Wheel 4 (FR)", displayTime},
       wheelFR_MOIY               { "J__Wheel_y_4", "kg*m^2*°", "Solid Wheel 4 (FR)", displayTime},
       wheelFR_MOIZ               { "J__Wheel_z_4", "kg*m^2*°", "Solid Wheel 4 (FR)", displayTime},

       wheelFRMassRim             { 1.45, "m__Rim_4", "kg", "Solid Wheel 4 (FR)"},
       wheelFRMassTyre            { 3.95, "m__Tyre_4", "kg", "Solid Wheel 4 (FR)"},
       wheelFRMassMotorAssembly   { 7.2, "m__Assembly_4", "kg", "Solid Wheel 4 (FR)"},

       wheelFR_JTyreX             { 0.166, "J__Tyre_x_4", "kg*m^2", "Solid Wheel 4 (FR)"},
       wheelFR_JTyreY             { 0.189, "J__Tyre_y_4", "kg*m^2", "Solid Wheel 4 (FR)"},
       wheelFR_JTyreZ             { 0.116, "J__Tyre_z_4", "kg*m^2", "Solid Wheel 4 (FR)"},
       wheelFR_JRimX              { 0.022, "J__Rim_x_4", "kg*m^2", "Solid Wheel 4 (FR)"},
       wheelFR_JRimY              { 0.035, "J__Rim_y_4", "kg*m^2", "Solid Wheel 4 (FR)"},
       wheelFR_JRimZ              { 0.022, "J__Rim_z_4", "kg*m^2", "Solid Wheel 4 (FR)"},
       wheelFR_JRotorTransmissionX{ 0.001, "J__RotorTransmi_x_4", "kg*m^2", "Solid Wheel 4 (FR)"},
       wheelFR_JRotorTransmissionY{ 0.004, "J__RotorTransmi_y_4", "kg*m^2", "Solid Wheel 4 (FR)"},
       wheelFR_JRotorTransmissionZ{ 0.001, "J__RotorTransmi_z_4", "kg*m^2", "Solid Wheel 4 (FR)"},

       wheelFR_dMotorAssemblyX    { 0.00, "l__Assembly_x_4", "m", "Solid Wheel 4 (FR)"},
       wheelFR_dMotorAssemblyY    { 0.02, "l__Assembly_y_4", "m", "Solid Wheel 4 (FR)"},
       wheelFR_dMotorAssemblyZ    { 0.02, "l__Assembly_z_4", "m", "Solid Wheel 4 (FR)"},

       wheelFRPosX                { "r__Wheel_x_4", "m", "Solid Wheel 4 (FR)", displayTime},
       wheelFRPosY                { "r__Wheel_y_4", "m", "Solid Wheel 4 (FR)", displayTime},
       wheelFRPosZ                { "r__Wheel_z_4", "m", "Solid Wheel 4 (FR)", displayTime},

       wheelFRVeloX               { "v__Wheel_x_4", "m/s", "Solid Wheel 4 (FR)", displayTime},
       wheelFRVeloY               { "v__Wheel_y_4", "m/s", "Solid Wheel 4 (FR)", displayTime},
       wheelFRVeloZ               { "v__Wheel_z_4", "m/s", "Solid Wheel 4 (FR)", displayTime},

       wheelFRAccelX              { "a__Wheel_x_4", "m/(s^2)", "Solid Wheel 4 (FR)", displayTime},
       wheelFRAccelY              { "a__Wheel_y_4", "m/(s^2)", "Solid Wheel 4 (FR)", displayTime},
       wheelFRAccelZ              { "a__Wheel_z_4", "m/(s^2)", "Solid Wheel 4 (FR)", displayTime},

       wheelFRAngularVeloX        { "rotVelo_x_Wheel_4", "°/s", "Solid Wheel 4 (FR)", displayTime},
       wheelFRAngularVeloY        { "rotVelo_y_Wheel_4", "°/s", "Solid Wheel 4 (FR)", displayTime},
       wheelFRAngularVeloZ        { "rotVelo_z_Wheel_4", "°/s", "Solid Wheel 4 (FR)", displayTime},

       wheelFRAngularAccelX       { "rotAccel_x_Wheel_4", "°/(s^2)", "Solid Wheel 4 (FR)", displayTime},
       wheelFRAngularAccelY       { "rotAccel_y_Wheel_4", "°/(s^2)", "Solid Wheel 4 (FR)", displayTime},
       wheelFRAngularAccelZ       { "rotAccel_z_Wheel_4", "°/(s^2)", "Solid Wheel 4 (FR)", displayTime},

       wheelFREulerX              { "rot_x_Wheel_4", "°", "Solid Wheel 4 (FR)", displayTime},
       wheelFREulerY              { "rot_y_Wheel_4", "°", "Solid Wheel 4 (FR)", displayTime},
       wheelFREulerZ              { "rot_z_Wheel_4", "°", "Solid Wheel 4 (FR)", displayTime},

       wheelFR_Fz                 { "F__MFT_z_4", "N", "Solid Wheel 4 (FR)", displayTime},
       wheelFR_Fx                 { "F__MFT_x_4", "N", "Solid Wheel 4 (FR)", displayTime},
       wheelFR_k                  { "k__4", " ", "Solid Wheel 4 (FR)", displayTime},
       wheelFR_ux                 { "u__x_4", " ", "Solid Wheel 4 (FR)", displayTime},
       wheelFRMrollingResistanceY { "M__MFT_y_4", "Nm", "Solid Wheel 4 (FR)", displayTime},
       wheelFRMoverturningCoupleX { "M__MFT_x_4", "Nm", "Solid Wheel 4 (FR)", displayTime},

     //Wheel Rear Left
       wheelRL_sx                 { -0.758, "s__Wheel_x_2", "m", "Solid Wheel 2 (RL)"},
       wheelRL_sy                 { 0.575, "s__Wheel_y_2", "m", "Solid Wheel 2 (RL)"},
       wheelRL_sz                 { 0.05, "s__Wheel_z_2", "m", "Solid Wheel 2 (RL)"},

       wheelRL_mass               { "m__Wheel_2", "kg", "Solid Wheel 2 (RL)", displayTime},
       wheelRL_MOIX               { "J__Wheel_x_2", "kg*m^2*°", "Solid Wheel 2 (RL)", displayTime},
       wheelRL_MOIY               { "J__Wheel_y_2", "kg*m^2*°", "Solid Wheel 2 (RL)", displayTime},
       wheelRL_MOIZ               { "J__Wheel_z_2", "kg*m^2*°", "Solid Wheel 2 (RL)", displayTime},

       wheelRLMassRim             { 1.45, "m__Rim_2", "kg", "Solid Wheel 2 (RL)"},
       wheelRLMassTyre            { 3.95, "m__Tyre_2", "kg", "Solid Wheel 2 (RL)"},
       wheelRLMassMotorAssembly   { 6.7, "m__Assembly_2", "kg", "Solid Wheel 2 (RL)"},

       wheelRL_JTyreX             { 0.116, "J__Tyre_x_2", "kg*m^2", "Solid Wheel 2 (RL)"},
       wheelRL_JTyreY             { 0.189, "J__Tyre_y_2", "kg*m^2", "Solid Wheel 2 (RL)"},
       wheelRL_JTyreZ             { 0.116, "J__Tyre_z_2", "kg*m^2", "Solid Wheel 2 (RL)"},
       wheelRL_JRimX              { 0.022, "J__Rim_x_2", "kg*m^2", "Solid Wheel 2 (RL)"},
       wheelRL_JRimY              { 0.035, "J__Rim_y_2", "kg*m^2", "Solid Wheel 2 (RL)"},
       wheelRL_JRimZ              { 0.022, "J__Rim_z_2", "kg*m^2", "Solid Wheel 2 (RL)"},
       wheelRL_JRotorTransmissionX{ 0.001, "J__RotorTransmi_x_2", "kg*m^2", "Solid Wheel 2 (RL)"},
       wheelRL_JRotorTransmissionY{ 0.004, "J__RotorTransmi_y_2", "kg*m^2", "Solid Wheel 2 (RL)"},
       wheelRL_JRotorTransmissionZ{ 0.001, "J__RotorTransmi_z_2", "kg*m^2", "Solid Wheel 2 (RL)"},

       wheelRL_dMotorAssemblyX    { 0.00, "l__Assembly_x_2", "m", "Solid Wheel 2 (RL)"},
       wheelRL_dMotorAssemblyY    { -0.02, "l__Assembly_y_2", "m", "Solid Wheel 2 (RL)"},
       wheelRL_dMotorAssemblyZ    { 0.02, "l__Assembly_z_2", "m", "Solid Wheel 2 (RL)"},

       wheelRLPosX                { "r__Wheel_x_2", "m" ,"Solid Wheel 2 (RL)", displayTime},
       wheelRLPosY                { "r__Wheel_y_2", "m" ,"Solid Wheel 2 (RL)", displayTime},
       wheelRLPosZ                { "r__Wheel_z_2", "m" ,"Solid Wheel 2 (RL)", displayTime},

       wheelRLVeloX               { "v__Wheel_x_2", "m/s", "Solid Wheel 2 (RL)", displayTime},
       wheelRLVeloY               { "v__Wheel_y_2", "m/s", "Solid Wheel 2 (RL)", displayTime},
       wheelRLVeloZ               { "v__Wheel_z_2", "m/s", "Solid Wheel 2 (RL)", displayTime},

       wheelRLAccelX              { "a__Wheel_x_2", "m/(s^2)", "Solid Wheel 2 (RL)", displayTime},
       wheelRLAccelY              { "a__Wheel_y_2", "m/(s^2)", "Solid Wheel 2 (RL)", displayTime},
       wheelRLAccelZ              { "a__Wheel_z_2", "m/(s^2)", "Solid Wheel 2 (RL)", displayTime},

       wheelRLAngularVeloX        { "rotVelo_x_Wheel_2", "°/s", "Solid Wheel 2 (RL)", displayTime},
       wheelRLAngularVeloY        { "rotVelo_y_Wheel_2", "°/s", "Solid Wheel 2 (RL)", displayTime},
       wheelRLAngularVeloZ        { "rotVelo_z_Wheel_2", "°/s", "Solid Wheel 2 (RL)", displayTime},

       wheelRLAngularAccelX       { "rotAccel_x_Wheel_2", "°/(s^2)", "Solid Wheel 2 (RL)", displayTime},
       wheelRLAngularAccelY       { "rotAccel_y_Wheel_2", "°/(s^2)", "Solid Wheel 2 (RL)", displayTime},
       wheelRLAngularAccelZ       { "rotAccel_z_Wheel_2", "°/(s^2)", "Solid Wheel 2 (RL)", displayTime},

       wheelRLEulerX              { "rot_x_Wheel_2", "°", "Solid Wheel 2 (RL)", displayTime},
       wheelRLEulerY              { "rot_y_Wheel_2", "°", "Solid Wheel 2 (RL)", displayTime},
       wheelRLEulerZ              { "rot_z_Wheel_2", "°", "Solid Wheel 2 (RL)", displayTime},

       wheelRL_Fz                 { "F__MFT_z_2", "N", "Solid Wheel 2 (RL)", displayTime},
       wheelRL_Fx                 { "F__MFT_x_2", "N", "Solid Wheel 2 (RL)", displayTime},
       wheelRL_k                  { "k__2", " ", "Solid Wheel 2 (RL)", displayTime},
       wheelRL_ux                 { "u__x_2", " ", "Solid Wheel 2 (RL)", displayTime},
       wheelRLMrollingResistanceY { "M__MFT_y_2", "Nm", "Solid Wheel 2 (RL)", displayTime},
       wheelRLMoverturningCoupleX { "M__MFT_x_2", "Nm", "Solid Wheel 2 (RL)", displayTime},

     //Wheel Rear Right
       wheelRR_sx                 { -0.758, "s__Wheel_x_3", "m", "Solid Wheel 3 (RR)"}, //0.763
       wheelRR_sy                 { -0.575, "s__Wheel_y_3", "m", "Solid Wheel 3 (RR)"},
       wheelRR_sz                 { 0.05, "s__Wheel_z_3", "m", "Solid Wheel 3 (RR)"},

       wheelRR_mass               { "m__Wheel_3", "kg", "Solid Wheel 3 (RR)", displayTime},
       wheelRR_MOIX               { "J__Wheel_x_3", "kg*m^2*°", "Solid Wheel 3 (RR)", displayTime},
       wheelRR_MOIY               { "J__Wheel_y_3", "kg*m^2*°", "Solid Wheel 3 (RR)", displayTime},
       wheelRR_MOIZ               { "J__Wheel_z_3", "kg*m^2*°", "Solid Wheel 3 (RR)", displayTime},

       wheelRRMassRim             { 1.45, "m__Rim_3", "kg", "Solid Wheel 3 (RR)"},
       wheelRRMassTyre            { 3.95, "m__Tyre_3", "kg", "Solid Wheel 3 (RR)"},
       wheelRRMassMotorAssembly   { 6.7, "m__Assembly_3", "kg", "Solid Wheel 3 (RR)"},

       wheelRR_JTyreX             { 0.116, "J__Tyre_x_3", "kg*m^2", "Solid Wheel 3 (RR)"},
       wheelRR_JTyreY             { 0.189, "J__Tyre_y_3", "kg*m^2", "Solid Wheel 3 (RR)"},
       wheelRR_JTyreZ             { 0.116, "J__Tyre_z_3", "kg*m^2", "Solid Wheel 3 (RR)"},
       wheelRR_JRimX              { 0.022, "J__Rim_x_3", "kg*m^2", "Solid Wheel 3 (RR)"},
       wheelRR_JRimY              { 0.035, "J__Rim_y_3", "kg*m^2", "Solid Wheel 3 (RR)"},
       wheelRR_JRimZ              { 0.022, "J__Rim_z_3", "kg*m^2", "Solid Wheel 3 (RR)"},
       wheelRR_JRotorTransmissionX{ 0.001, "J__RotorTransmi_x_3", "kg*m^2", "Solid Wheel 3 (RR)"},
       wheelRR_JRotorTransmissionY{ 0.004, "J__RotorTransmi_y_3", "kg*m^2", "Solid Wheel 3 (RR)"},
       wheelRR_JRotorTransmissionZ{ 0.001, "J__RotorTransmi_z_3", "kg*m^2", "Solid Wheel 3 (RR)"},

       wheelRR_dMotorAssemblyX    { 0.00, "l__Assembly_x_3", "m", "Solid Wheel 3 (RR)"},
       wheelRR_dMotorAssemblyY    { 0.02, "l__Assembly_y_3", "m", "Solid Wheel 3 (RR)"},
       wheelRR_dMotorAssemblyZ    { 0.02, "l__Assembly_z_3", "m", "Solid Wheel 3 (RR)"},

       wheelRRPosX                { "r__Wheel_x_3", "m", "Solid Wheel 3 (RR)", displayTime},
       wheelRRPosY                { "r__Wheel_y_3", "m", "Solid Wheel 3 (RR)", displayTime},
       wheelRRPosZ                { "r__Wheel_z_3", "m", "Solid Wheel 3 (RR)", displayTime},

       wheelRRVeloX               { "v__Wheel_x_3", "m/s", "Solid Wheel 3 (RR)", displayTime},
       wheelRRVeloY               { "v__Wheel_y_3", "m/s", "Solid Wheel 3 (RR)", displayTime},
       wheelRRVeloZ               { "v__Wheel_z_3", "m/s", "Solid Wheel 3 (RR)", displayTime},

       wheelRRAccelX              { "a__Wheel_x_3", "m/(s^2)", "Solid Wheel 3 (RR)", displayTime},
       wheelRRAccelY              { "a__Wheel_y_3", "m/(s^2)", "Solid Wheel 3 (RR)", displayTime},
       wheelRRAccelZ              { "a__Wheel_z_3", "m/(s^2)", "Solid Wheel 3 (RR)", displayTime},

       wheelRRAngularVeloX        { "rotVelo_x_Wheel_3", "°/s", "Solid Wheel 3 (RR)", displayTime},
       wheelRRAngularVeloY        { "rotVelo_y_Wheel_3", "°/s", "Solid Wheel 3 (RR)", displayTime},
       wheelRRAngularVeloZ        { "rotVelo_z_Wheel_3", "°/s", "Solid Wheel 3 (RR)", displayTime},

       wheelRRAngularAccelX       { "rotAccel_x_Wheel_3", "°/(s^2)", "Solid Wheel 3 (RR)", displayTime},
       wheelRRAngularAccelY       { "rotAccel_y_Wheel_3", "°/(s^2)", "Solid Wheel 3 (RR)", displayTime},
       wheelRRAngularAccelZ       { "rotAccel_z_Wheel_3", "°/(s^2)", "Solid Wheel 3 (RR)", displayTime},

       wheelRREulerX              { "rot_x_Wheel_3", "°", "Solid Wheel 3 (RR)", displayTime},
       wheelRREulerY              { "rot_y_Wheel_3", "°", "Solid Wheel 3 (RR)", displayTime},
       wheelRREulerZ              { "rot_z_Wheel_3", "°", "Solid Wheel 3 (RR)", displayTime},

       wheelRR_Fz                 { "F__MFT_z_3", "N", "Solid Wheel 3 (RR)", displayTime},
       wheelRR_Fx                 { "F__MFT_x_3", "N", "Solid Wheel 3 (RR)", displayTime},
       wheelRR_k                  { "k__3", " ", "Solid Wheel 3 (RR)", displayTime},
       wheelRR_ux                 { "u__x_3", " ", "Solid Wheel 3 (RR)", displayTime},
       wheelRRMrollingResistanceY { "M__MFT_y_3", "Nm", "Solid Wheel 3 (RR)", displayTime},
       wheelRRMoverturningCoupleX { "M__MFT_x_3", "Nm", "Solid Wheel 3 (RR)", displayTime},

     //Main
       mainInitPosX               { 13.17, "r__Mainbody_x_init", "m", "Solid Mainbody"},
       mainInitPosY               { 0.0, "r__Mainbody_y_init", "m", "Solid Mainbody"},
       mainInitPosZ               { 0.285, "r__Mainbody_z_init", "m","Solid Mainbody"},

       mainMass                   { 111.38, "m__Mainbody", "kg", "Solid Mainbody"},
       driverMass                 { 53.0, "m__Driver", "kg", "Solid Mainbody"},

       sxDriver                   { 0.05, "s__Driver_x", "m", "Solid Mainbody"},
       syDriver                   { 0.00, "s__Driver_y", "m", "Solid Mainbody"},
       szDriver                   { 0.012, "s__Driver_z", "m","Solid Mainbody"},

       main_JX                    { 32.487, "J__Mainbody_x_init", "kg*m^2", "Solid Mainbody"},
       main_JY                    { 41.1, "J__Mainbody_y_init", "kg*m^2", "Solid Mainbody"},
       main_JZ                    { 68.289, "J__Mainbody_z_init", "kg*m^2", "Solid Mainbody"},

       main_mass                  { "m__Mainbody", "kg", "Solid Mainbody", displayTime},
       main_MOIX                  { "J__Mainbody_x", "kg*m^2*°", "Solid Mainbody", displayTime},
       main_MOIY                  { "J__Mainbody_y", "kg*m^2*°", "Solid Mainbody", displayTime},
       main_MOIZ                  { "J__Mainbody_z", "kg*m^2*°", "Solid Mainbody", displayTime},

       mainPosX                   { "r__Mainbody_x", "m", "Solid Mainbody", displayTime},
       mainPosY                   { "r__Mainbody_y", "m", "Solid Mainbody", displayTime},
       mainPosZ                   { "r__Mainbody_z", "m", "Solid Mainbody", displayTime},

       mainVeloX                  { "v__Mainbody_x", "m/s", "Solid Mainbody", displayTime},
       mainVeloY                  { "v__Mainbody_y", "m/s", "Solid Mainbody", displayTime},
       mainVeloZ                  { "v__Mainbody_z", "m/s", "Solid Mainbody", displayTime},

       mainAccelX                 { "a__Mainbody_x", "m/(s^2)", "Solid Mainbody", displayTime},
       mainAccelY                 { "a__Mainbody_y", "m/(s^2)", "Solid Mainbody", displayTime},
       mainAccelZ                 { "a__Mainbody_z", "m/(s^2)", "Solid Mainbody", displayTime},

       mainAngularVeloX           { "rotVelo_Mainbody_x", "°/s", "Solid Mainbody", displayTime},
       mainAngularVeloY           { "rotVelo_Mainbody_y", "°/s", "Solid Mainbody", displayTime},
       mainAngularVeloZ           { "rotVelo_Mainbody_z", "°/s", "Solid Mainbody", displayTime},

       mainAngularAccelX          { "rotAccel_Mainbody_x", "°/(s^2)", "Solid Mainbody", displayTime},
       mainAngularAccelY          { "rotAccel_Mainbody_y", "°/(s^2)", "Solid Mainbody", displayTime},
       mainAngularAccelZ          { "rotAccel_Mainbody_z", "°/(s^2)", "Solid Mainbody", displayTime},

       mainEulerX                 { "rot_Mainbody_x", "°", "Solid Mainbody", displayTime},
       mainEulerY                 { "rot_Mainbody_y", "°", "Solid Mainbody", displayTime},
       mainEulerZ                 { "rot_Mainbody_z", "°", "Solid Mainbody", displayTime},

       //Aero
       aero_cl                    { -2.0, "C__l", "", "Joint Aerodynamic"},
       aero_cd                    { 1.0, "C__d", "", "Joint Aerodynamic"},
       aero_clalpha               { 0.06, "C__la", "/°", "Joint Aerodynamic"},
       aero_cdalpha               { 0.08, "C__da", "/°", "Joint Aerodynamic"},
       aero_A                     { 1.0, "A", "m^2", "Joint Aerodynamic"},
       aero_roh                   { 1.225, "roh", "kg/(m^3)", "Joint Aerodynamic"},
       aeroEnabled                { 1.0, "AeroJointEnabled", "", "Joint Aerodynamic"},
       aero_sx                    { -0.112, "s__x", "m", "Joint Aerodynamic"},
       aeroFz                     { "F__Aero_z", "N", "Aero", displayTime},
       aeroFx                     { "F__Aero_x", "N", "Aero", displayTime},


     // MFT - Parameter 80kPa
       //general
       Fz0                        { 800.0, "F__MFT_z0", "N", "MFT Parameter"},
       R0                         { 0.235, "r__0", "m", "MFT Parameter"},
       c_tyre                     { 98820.0, "c__Tyre", "N/m", "MFT Parameter"},
       d_tyre                     { 3429.0, "d__Tyre", "kg/s", "MFT Parameter"},

       //lon Coeff
       p_Cx1                      { 1.786, "p__Cx1", " ", "MFT Parameter"},
       p_Dx1                      { 2.688, "p__Dx1", " ", "MFT Parameter"},
       p_Dx2                      { -0.272, "p__Dx2", " ", "MFT Parameter"},
       p_Dx3                      { 13.700, "p__Dx3", " ", "MFT Parameter"},
       p_Ex1                      { 0.871, "p__Ex1", " ", "MFT Parameter"},
       p_Ex2                      { -0.038, "p__Ex2", " ", "MFT Parameter"},
       p_Ex3                      { 0.000 , "p__Ex3", " ", "MFT Parameter"},
       p_Ex4                      { 0.071 , "p__Ex4", " ", "MFT Parameter"},
       p_Kx1                      { 81.250 , "p__Kx1", " ", "MFT Parameter"},
       p_Kx2                      { -20.250 , "p__Kx2", " ", "MFT Parameter"},
       p_Kx3                      { 0.500 , "p__Kx3", " ", "MFT Parameter"},
       p_Hx1                      { 0.000 , "p__Hx1", " ", "MFT Parameter"},
       p_Hx2                      { 0.000 , "p__Hx2", " ", "MFT Parameter"},
       p_Vx1                      { 0.000 , "p__Vx1", " ", "MFT Parameter"},
       p_Vx2                      { 0.000 , "p__Vx2", " ", "MFT Parameter"},
       //Scaling Factors
       l_Cx                       { 1.000 , "lambda__Cx", " ", "MFT Parameter"},
       l_Mux                      { 0.6 , "lambda__ux", " ", "MFT Parameter"},
       l_Ex                       { 1.000 , "lambda__Ex", " ", "MFT Parameter"},
       l_KxK                      { 1.000 , "lambda__Kxk", " ", "MFT Parameter"},
       l_Hx                       { 0.000 , "lambda__Hx", " ", "MFT Parameter"},
       l_Vx                       { 0.000 , "lambda__Vx", " ", "MFT Parameter"},
       l_My                       { 1.000 , "lambda__My", " ", "MFT Parameter"},
       l_Mx                       { 1.000 , "lambda__Mx", " ", "MFT Parameter"},
       l_Fz0                      { 1.000 , "lambda__Fz0", " ", "MFT Parameter"},
       //overturning Coefficient
       q_Sx1                      { 0.000 , "q__Sx1", " ", "MFT Parameter"},
       q_Sx2                      { 1.385 , "q__Sx2", " ", "MFT Parameter"},
       q_Sx3                      { -0.009965 , "q__Sx3", " ", "MFT Parameter"},
       //rolling Coeff
       q_Sy1                      { -0.0309 , "q__Sy1", " ", "MFT Parameter"},
       q_Sy2                      { -0.0921 , "q__Sy2", " ", "MFT Parameter"},

       //Energy
       wheelSusFLEnergyFlow       { "W__Wheel_1", "kJ", "Energy", displayTime},
       wheelSusFREnergyFlow       { "W__Wheel_4", "kJ", "Energy", displayTime},
       wheelSusRLEnergyFlow       { "W__Wheel_2", "kJ", "Energy", displayTime},
       wheelSusRREnergyFlow       { "W__Wheel_3", "kJ", "Energy", displayTime},

       MotorFLEnergyFlow          { "W__Motor_1", "kJ", "Energy", displayTime},
       MotorFREnergyFlow          { "W__Motor_4", "kJ", "Energy", displayTime},
       MotorRLEnergyFlow          { "W__Motor_2", "kJ", "Energy", displayTime},
       MotorRREnergyFlow          { "W__Motor_3", "kJ", "Energy", displayTime},

       aeroEnergyFlow             { "W__Aero", "kJ", "Energy", displayTime},

       wheelFL_energy             { "E__Wheel_1", "kJ", "Energy", displayTime},
       wheelFR_energy             { "E__Wheel_4", "kJ", "Energy", displayTime},
       wheelRL_energy             { "E__Wheel_2", "kJ", "Energy", displayTime},
       wheelRR_energy             { "E__Wheel_3", "kJ", "Energy", displayTime},

       main_energy                { "E__Main", "kJ", "Energy", displayTime},

       difference_energy          { "ΔE__total", "kJ", "Energy", displayTime},
       total_energy               { "E__total", "kJ", "Energy", displayTime},
       total_energyFlow           { "W__total", "kJ", "Energy", displayTime}

        //Initialisation of Values END
       {
        qDebug() << "VALUES. All values Loaded" ;

    }

    //available Values BEGINN

    //General
    Parameter initTimestep;
    Parameter timestep;
    Parameter displayTime;
    Parameter totalSimulationTime;
    Parameter playbackSpeed;
    Parameter totalCalculationTime;
    Parameter chartZoom;
    Value calculationTimePerStep;

    //Simulation Environment
    Parameter g;

    //Joints

    Parameter wheelSusRealc;
    Parameter wheelSusReald;

    //WheelFL - SuspensionFL
    Parameter wheelSusFL_sx;
    Parameter wheelSusFL_sy;
    Parameter wheelSusFL_sz;
    Parameter wheelSusFLMass;
    Parameter wheelSusFLEnabled;

    Value wheelSusFLForceX;
    Value wheelSusFLForceY;
    Value wheelSusFLForceZ;

    Value wheelSusFLTorqueX;
    Value wheelSusFLTorqueY;
    Value wheelSusFLTorqueZ;

    //WheelFR - SuspensionFR
    Parameter wheelSusFR_sx;
    Parameter wheelSusFR_sy;
    Parameter wheelSusFR_sz;
    Parameter wheelSusFRMass;
    Parameter wheelSusFREnabled;

    Value wheelSusFRForceX;
    Value wheelSusFRForceY;
    Value wheelSusFRForceZ;

    Value wheelSusFRTorqueX;
    Value wheelSusFRTorqueY;
    Value wheelSusFRTorqueZ;

    //WheelRL - SuspensionRL
    Parameter wheelSusRL_sx;
    Parameter wheelSusRL_sy;
    Parameter wheelSusRL_sz;
    Parameter wheelSusRLMass;
    Parameter wheelSusRLEnabled;

    Value wheelSusRLForceX;
    Value wheelSusRLForceY;
    Value wheelSusRLForceZ;

    Value wheelSusRLTorqueX;
    Value wheelSusRLTorqueY;
    Value wheelSusRLTorqueZ;

    //WheelRR - SuspensionRR
    Parameter wheelSusRR_sx;
    Parameter wheelSusRR_sy;
    Parameter wheelSusRR_sz;
    Parameter wheelSusRRMass;
    Parameter wheelSusRREnabled;

    Value wheelSusRRForceX;
    Value wheelSusRRForceY;
    Value wheelSusRRForceZ;

    Value wheelSusRRTorqueX;
    Value wheelSusRRTorqueY;
    Value wheelSusRRTorqueZ;

    //Motors
    Value torqueMotorFL;
    Value powerMotorFL;
    Parameter torqueMotorEnabledFL;
    Parameter torqueMotorMaxFL;
    Parameter powerMotorMaxFL;
    Value torqueMotorFR;
    Value powerMotorFR;
    Parameter torqueMotorEnabledFR;
    Parameter torqueMotorMaxFR;
    Parameter powerMotorMaxFR;
    Value torqueMotorRL;
    Value powerMotorRL;
    Parameter torqueMotorEnabledRL;
    Parameter torqueMotorMaxRL;
    Parameter powerMotorMaxRL;
    Value torqueMotorRR;
    Value powerMotorRR;
    Parameter torqueMotorEnabledRR;
    Parameter torqueMotorMaxRR;
    Parameter powerMotorMaxRR;

    //MotorController
    Parameter MotorC_keff;
    Parameter motorC_Kp;
    Parameter motorC_Ki;
    Parameter motorC_eimax;
    Parameter motorC_eimin;
    Parameter motorC_Kd;

    Value motorCFL_e;
    Value motorCFR_e;
    Value motorCRL_e;
    Value motorCRR_e;

    //Wheel
    //Front Left
    Parameter wheelFL_sx;
    Parameter wheelFL_sy;
    Parameter wheelFL_sz;

    Value wheelFL_mass;
    Value wheelFL_MOIX;
    Value wheelFL_MOIY;
    Value wheelFL_MOIZ;
    
    Parameter wheelFLMassRim;
    Parameter wheelFLMassTyre;
    Parameter wheelFLMassMotorAssembly;

    Parameter wheelFL_JTyreX;
    Parameter wheelFL_JTyreY;
    Parameter wheelFL_JTyreZ;
    Parameter wheelFL_JRimX;
    Parameter wheelFL_JRimY;
    Parameter wheelFL_JRimZ;
    Parameter wheelFL_JRotorTransmissionX;
    Parameter wheelFL_JRotorTransmissionY;
    Parameter wheelFL_JRotorTransmissionZ;
    
    Parameter wheelFL_dMotorAssemblyX;
    Parameter wheelFL_dMotorAssemblyY;
    Parameter wheelFL_dMotorAssemblyZ;

    Value wheelFLPosX;
    Value wheelFLPosY;
    Value wheelFLPosZ;

    Value wheelFLVeloX;
    Value wheelFLVeloY;
    Value wheelFLVeloZ;

    Value wheelFLAccelX;
    Value wheelFLAccelY;
    Value WheelFLAccelZ;

    Value wheelFLAngularVeloX;
    Value wheelFLAngularVeloY;
    Value wheelFLAngularVeloZ;

    Value wheelFLAngularAccelX;
    Value wheelFLAngularAccelY;
    Value wheelFLAngularAccelZ;

    Value wheelFLEulerX;
    Value wheelFLEulerY;
    Value wheelFLEulerZ;

    Value wheelFL_Fz;
    Value wheelFL_Fx;
    Value wheelFL_k;
    Value wheelFL_ux;
    Value wheelFLMrollingResistanceY;
    Value wheelFLMoverturningCoupleX;

    Value wheelFLDisplacementWheelToBody;

    //Front Right
    Parameter wheelFR_sx;
    Parameter wheelFR_sy;
    Parameter wheelFR_sz;

    Value wheelFR_mass;
    Value wheelFR_MOIX;
    Value wheelFR_MOIY;
    Value wheelFR_MOIZ;

    Parameter wheelFRMassRim;
    Parameter wheelFRMassTyre;
    Parameter wheelFRMassMotorAssembly;

    Parameter wheelFR_JTyreX;
    Parameter wheelFR_JTyreY;
    Parameter wheelFR_JTyreZ;
    Parameter wheelFR_JRimX;
    Parameter wheelFR_JRimY;
    Parameter wheelFR_JRimZ;
    Parameter wheelFR_JRotorTransmissionX;
    Parameter wheelFR_JRotorTransmissionY;
    Parameter wheelFR_JRotorTransmissionZ;

    Parameter wheelFR_dMotorAssemblyX;
    Parameter wheelFR_dMotorAssemblyY;
    Parameter wheelFR_dMotorAssemblyZ;

    Value wheelFRPosX;
    Value wheelFRPosY;
    Value wheelFRPosZ;

    Value wheelFRVeloX;
    Value wheelFRVeloY;
    Value wheelFRVeloZ;

    Value wheelFRAccelX;
    Value wheelFRAccelY;
    Value wheelFRAccelZ;

    Value wheelFRAngularVeloX;
    Value wheelFRAngularVeloY;
    Value wheelFRAngularVeloZ;

    Value wheelFRAngularAccelX;
    Value wheelFRAngularAccelY;
    Value wheelFRAngularAccelZ;

    Value wheelFREulerX;
    Value wheelFREulerY;
    Value wheelFREulerZ;

    Value wheelFR_Fz;
    Value wheelFR_Fx;
    Value wheelFR_k;
    Value wheelFR_ux;
    Value wheelFRMrollingResistanceY;
    Value wheelFRMoverturningCoupleX;

    //Rear Left
    Parameter wheelRL_sx;
    Parameter wheelRL_sy;
    Parameter wheelRL_sz;

    Value wheelRL_mass;
    Value wheelRL_MOIX;
    Value wheelRL_MOIY;
    Value wheelRL_MOIZ;

    Parameter wheelRLMassRim;
    Parameter wheelRLMassTyre;
    Parameter wheelRLMassMotorAssembly;

    Parameter wheelRL_JTyreX;
    Parameter wheelRL_JTyreY;
    Parameter wheelRL_JTyreZ;
    Parameter wheelRL_JRimX;
    Parameter wheelRL_JRimY;
    Parameter wheelRL_JRimZ;
    Parameter wheelRL_JRotorTransmissionX;
    Parameter wheelRL_JRotorTransmissionY;
    Parameter wheelRL_JRotorTransmissionZ;

    Parameter wheelRL_dMotorAssemblyX;
    Parameter wheelRL_dMotorAssemblyY;
    Parameter wheelRL_dMotorAssemblyZ;

    Value wheelRLPosX;
    Value wheelRLPosY;
    Value wheelRLPosZ;

    Value wheelRLVeloX;
    Value wheelRLVeloY;
    Value wheelRLVeloZ;

    Value wheelRLAccelX;
    Value wheelRLAccelY;
    Value wheelRLAccelZ;

    Value wheelRLAngularVeloX;
    Value wheelRLAngularVeloY;
    Value wheelRLAngularVeloZ;

    Value wheelRLAngularAccelX;
    Value wheelRLAngularAccelY;
    Value wheelRLAngularAccelZ;

    Value wheelRLEulerX;
    Value wheelRLEulerY;
    Value wheelRLEulerZ;

    Value wheelRL_Fz;
    Value wheelRL_Fx;
    Value wheelRL_k;
    Value wheelRL_ux;
    Value wheelRLMrollingResistanceY;
    Value wheelRLMoverturningCoupleX;

    //Rear Right
    Parameter wheelRR_sx;
    Parameter wheelRR_sy;
    Parameter wheelRR_sz;

    Value wheelRR_mass;
    Value wheelRR_MOIX;
    Value wheelRR_MOIY;
    Value wheelRR_MOIZ;

    Parameter wheelRRMassRim;
    Parameter wheelRRMassTyre;
    Parameter wheelRRMassMotorAssembly;

    Parameter wheelRR_JTyreX;
    Parameter wheelRR_JTyreY;
    Parameter wheelRR_JTyreZ;
    Parameter wheelRR_JRimX;
    Parameter wheelRR_JRimY;
    Parameter wheelRR_JRimZ;
    Parameter wheelRR_JRotorTransmissionX;
    Parameter wheelRR_JRotorTransmissionY;
    Parameter wheelRR_JRotorTransmissionZ;

    Parameter wheelRR_dMotorAssemblyX;
    Parameter wheelRR_dMotorAssemblyY;
    Parameter wheelRR_dMotorAssemblyZ;

    Value wheelRRPosX;
    Value wheelRRPosY;
    Value wheelRRPosZ;

    Value wheelRRVeloX;
    Value wheelRRVeloY;
    Value wheelRRVeloZ;

    Value wheelRRAccelX;
    Value wheelRRAccelY;
    Value wheelRRAccelZ;

    Value wheelRRAngularVeloX;
    Value wheelRRAngularVeloY;
    Value wheelRRAngularVeloZ;

    Value wheelRRAngularAccelX;
    Value wheelRRAngularAccelY;
    Value wheelRRAngularAccelZ;

    Value wheelRREulerX;
    Value wheelRREulerY;
    Value wheelRREulerZ;

    Value wheelRR_Fz;
    Value wheelRR_Fx;
    Value wheelRR_k;
    Value wheelRR_ux;
    Value wheelRRMrollingResistanceY;
    Value wheelRRMoverturningCoupleX;

    //Main Body
    Parameter mainInitPosX;
    Parameter mainInitPosY;
    Parameter mainInitPosZ;

    Parameter mainMass;
    Parameter driverMass;

    Parameter sxDriver;
    Parameter syDriver;
    Parameter szDriver;

    Parameter main_JX;
    Parameter main_JY;
    Parameter main_JZ;

    Value main_mass;
    Value main_MOIX;
    Value main_MOIY;
    Value main_MOIZ;

    Value mainPosX;
    Value mainPosY;
    Value mainPosZ;

    Value mainVeloX;
    Value mainVeloY;
    Value mainVeloZ;

    Value mainAccelX;
    Value mainAccelY;
    Value mainAccelZ;

    Value mainAngularVeloX;
    Value mainAngularVeloY;
    Value mainAngularVeloZ;

    Value mainAngularAccelX;
    Value mainAngularAccelY;
    Value mainAngularAccelZ;

    Value mainEulerX;
    Value mainEulerY;
    Value mainEulerZ;

    //Aero
    Parameter aero_cl;
    Parameter aero_cd;
    Parameter aero_clalpha;
    Parameter aero_cdalpha;
    Parameter aero_A;
    Parameter aero_roh;
    Parameter aeroEnabled;
    Parameter aero_sx;

    Value aeroFz;
    Value aeroFx;

    //MFT Parameters
    //General
    Parameter Fz0;
    Parameter R0;
    Parameter c_tyre;
    Parameter d_tyre;

    //longitudinal Coeff
    Parameter p_Cx1;
    Parameter p_Dx1;
    Parameter p_Dx2;
    Parameter p_Dx3;
    Parameter p_Ex1;
    Parameter p_Ex2;
    Parameter p_Ex3;
    Parameter p_Ex4;
    Parameter p_Kx1;
    Parameter p_Kx2;
    Parameter p_Kx3;
    Parameter p_Hx1;
    Parameter p_Hx2;
    Parameter p_Vx1;
    Parameter p_Vx2;

    //scaling Factors
    Parameter l_Cx;
    Parameter l_Mux;
    Parameter l_Ex;
    Parameter l_KxK;
    Parameter l_Hx;
    Parameter l_Vx;
    Parameter l_My;
    Parameter l_Mx;
    Parameter l_Fz0;

    //overtuning Coeff
    Parameter q_Sx1;
    Parameter q_Sx2;
    Parameter q_Sx3;

    //rolling Coeff
    Parameter q_Sy1;
    Parameter q_Sy2;


    //Energy
    Value wheelSusFLEnergyFlow;
    Value wheelSusFREnergyFlow;
    Value wheelSusRLEnergyFlow;
    Value wheelSusRREnergyFlow;
    Value MotorFLEnergyFlow;
    Value MotorFREnergyFlow;
    Value MotorRLEnergyFlow;
    Value MotorRREnergyFlow;
    Value aeroEnergyFlow;
    Value wheelFL_energy;
    Value wheelFR_energy;
    Value wheelRL_energy;
    Value wheelRR_energy;
    Value main_energy;
    Value difference_energy;
    Value total_energy;
    Value total_energyFlow;



    //available Values END

    static Data& instance()         {
        static Data instance;
        return instance;
    }

    Data(Data const&)          = delete;
    void operator=(Data const&)  = delete;

};


#endif // VALUES_H
