#include <main.h>


void addProperty(const QString name, QObject *obj){
    engine_ptr->rootContext()->setContextProperty(name, obj);
    //qDebug() << "MAIN: Property added " << name;
}


int main(int argc, char **argv)
{
    qDebug(" ");
    qDebug("");
    qDebug("//////////////////////////////////////////////////////////");
    qDebug("//////////////////////////////////////////////////////////");
    qDebug("//////////////////////////////////////////////////////////");
    qDebug("//////////////////////////////////////////////////////////");
    qDebug("//////////////////////////////////////////////////////////");
    qDebug("");
    qDebug("EFR Full Vehicle Simulation v1.0 by Hans Blaettermann ");
    qDebug("h.blaett@gmail.com");
    qDebug("---");
    qDebug("GIT:");
    qDebug("https://github.com/Olgidos/efrSIM ");
    qDebug("Credits: ");
    qDebug("Qt: https://www.qt.io/");
    qDebug("Icon made by https://smashicons.com/ from www.flaticon.com");
    qDebug("");
    qDebug("//////////////////////////////////////////////////////////");
    qDebug(" ");
    qDebug(" ");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine_ptr = &engine;

    qDebug() << "Engine created";
    Data::instance();
    SimController* controller = new SimController();
    qDebug() << "Model/Controller created";

    const QUrl url(QStringLiteral("qrc:/Viewer/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    qDebug() << "Engine loaded";

    double t = 0.0;
    double f = 0.0;

/*    MFT_FX_PureLongSlip(1529.9, 0.15, 3.9547, &t,  &f);
    qDebug() << "1400.0, 0.05, 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, 0.1, 3.9547, &t,  &f);
    qDebug() << "1400.0, 0.1, 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, 0.075, 3.9547, &t,  &f);
    qDebug() << "1400.0, 0.05, 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, 0.05, 3.9547, &t,  &f);
    qDebug() << "1400.0, -0.25, 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, 0.025, 3.9547, &t,  &f);
    qDebug() << "500.0 0.1 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, 0, 3.9547, &t,  &f);
    qDebug() << "500.0 -0.15 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, -0.025, 3.9547, &t,  &f);
    qDebug() << "1400.0, 0.05, 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, -0.05, 3.9547, &t,  &f);
    qDebug() << "500.0 -0.15 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, -0.075, 3.9547, &t,  &f);
    qDebug() << "1400.0, 0.05, 0.075" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, -0.1, 3.9547, &t,  &f);
    qDebug() << "500.0 -0.15 0.0" << t << " " << f;

    MFT_FX_PureLongSlip(1529.9, -0.15, 3.9547, &t,  &f);
    qDebug() << "800N 0.2 0.0" << t << " " << f;

    qDebug() << "Overturning " << MFT_MX_OverturningCouple(1000.0, 4.0 , 0);
    qDebug() << "Overturning " << MFT_MX_OverturningCouple(1000.0, 1.0 , 0);
    qDebug() << "Overturning " << MFT_MX_OverturningCouple(1000.0, 0.0 , 0);

    qDebug() << "Rolling Resistance " << MFT_MY_RollingResistance(1000.0, 20.0 , 3000);
    qDebug() << "Rolling Resistance " << MFT_MY_RollingResistance(1000.0, 10.0 , 3000);
    qDebug() << "Rolling Resistance " << MFT_MY_RollingResistance(1000.0, 0.0 , 3000);*/

    //MFT_FX_PureLongSlip(500, -0.15, 0, &t,  &f);
    //qDebug() << "500.0, -0.15, 0.0" << t << " " << f;


    engine.load(url);
    return app.exec();
}
