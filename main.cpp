#include <QApplication>
#include <FelgoApplication>

#include <QQmlApplicationEngine>

// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>
#include "hello.h"
#include <FelgoLiveClient>
#include "resource.h"
#include <iostream>


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    FelgoApplication felgo;

    QQmlApplicationEngine engine;
    qmlRegisterType<Hello>("qtcpp", 1, 0, "TaskRunner");
    felgo.initialize(&engine);

    //快速测试C++后端代码用，考虑到向QML添加较为麻烦，临时放在这里。
    Resource res(42, "Hello, world!");
    int intValue = res.doSomethingInt();
    std::string& strValue = res.getStringValue();
    std::cout << "[Yami] Integer value: " << intValue << std::endl;
    std::cout << "[Yami] String value: " << strValue << std::endl;

    //快速测试C++后端代码用，考虑到向QML添加较为麻烦，临时放在这里。
    auto testNumber1 = std::make_unique<int>(100);
    auto testNumber2 = std::make_unique<int>(100);
    auto testNumber3 = *testNumber1 + *testNumber2;
    std::cout << "[Yami] testNumber value: " << testNumber3 << std::endl;

    auto testStr = std::make_unique<std::string>("Hello, 100!");
    std::cout << "[Yami] testStr value: " << *testStr << std::endl;


    // Set an optional license key from project file
    // This does not work if using Felgo Live, only for Felgo Cloud Builds and local builds
    felgo.setLicenseKey(PRODUCT_LICENSE_KEY);

    // use this during development
    // for PUBLISHING, use the entry point below
    // felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
    //felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

    // engine.load(QUrl(felgo.mainQmlFileName()));

    // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
    // and uncomment the line below
    //FelgoLiveClient client (&engine);
    FelgoLiveClient liveClient(&engine);

    return app.exec();
}
