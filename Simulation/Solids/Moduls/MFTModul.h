#ifndef MFTMODUL_H
#define MFTMODUL_H

#include <math.h>
#include <Model/data.h>
#include <Values/parameter.h>

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

static double dfz;
static double Cx;
static double Dx;
static double Ex;
static double Kxk;
static double Bx;
static double Shx;
static double Svx;
static double kx;

static void MFT_FX_PureLongSlip (double Fz, double k, double IA, double* Fx, double *ux) {
    IA = sin(IA/180.0 * M_PI);
    if(Fz < 0.0 ) Fz = 0.0;
    dfz = (Fz - Data::instance().Fz0.val()) / (Fz + 0.000001);
    Cx  = Data::instance().p_Cx1.val() * Data::instance().l_Cx.val();
    *ux  = (Data::instance().p_Dx1.val() + Data::instance().p_Dx2.val() * dfz) * (1 - Data::instance().p_Dx3.val() * IA * IA) * Data::instance().l_Mux.val();
    Dx  = *ux * Fz;

    Kxk = Fz * (Data::instance().p_Kx1.val() + Data::instance().p_Kx2.val() * dfz) * exp(Data::instance().p_Kx3.val() * dfz) * Data::instance().l_KxK.val();
    Bx  = Kxk / (Cx*Dx + 0.000001);
    Shx = (Data::instance().p_Hx1.val() + Data::instance().p_Hx2.val()*dfz) * Data::instance().l_Hx.val();
    Svx = Fz * (Data::instance().p_Vx1.val() + Data::instance().p_Vx2.val() * dfz) * Data::instance().l_Vx.val();
    kx  = k + Shx;
    Ex  = (Data::instance().p_Ex1.val() + Data::instance().p_Ex2.val() * dfz+ Data::instance().p_Ex3.val() * dfz * dfz)
            * (1.0 - Data::instance().p_Ex4.val() * sgn(kx)) * Data::instance().l_Ex.val();
    *Fx = Dx * sin(Cx * atan(Bx * kx - Ex * (Bx * kx - atan(Bx * kx)))) + Svx;
}

static double MFT_MY_RollingResistance (double Fz, double Vr, double Fx) {
    double V0 = sqrt(Data::instance().g.val() * Data::instance().R0.val());
    double Flz0 = Data::instance().l_Fz0.val() * Fz;
    return -Fz * Data::instance().R0.val() * (Data::instance().q_Sy1.val() * atan(Vr / V0) + Data::instance().q_Sy2.val() * Fx / Flz0 ) * Data::instance().l_My.val();
}

static double MFT_MX_OverturningCouple (double Fz, double IA, double Fy) {
    IA = sin(IA/180.0 * M_PI);
    double Flz0 = Data::instance().l_Fz0.val() * Fz;
    return Fz * Data::instance().R0.val() * (Data::instance().q_Sx1.val() - Data::instance().q_Sx2.val()*IA + Data::instance().q_Sx3.val() * Fy / Flz0 ) * Data::instance().l_Mx.val();
}

//static double MFT_My (double Fz, double k) {
//}


#endif // MFTMODUL_H
