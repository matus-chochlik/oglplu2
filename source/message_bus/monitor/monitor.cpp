#include "MonitorBackend.hpp"
#include "MonitorViewModel.hpp"
#include "NodeViewModel.hpp"
#include <eagine/main_ctx.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

namespace eagine {
//------------------------------------------------------------------------------
int argc_copy = 0;
const char** argv_copy = nullptr;
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    ctx.log().info("message bus monitor starting");

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app{argc_copy, const_cast<char**>(argv_copy)};

    const auto registerId = "com.github.matus-chochlik.oglplu2";

    qmlRegisterUncreatableType<MonitorTheme>(
      registerId, 1, 0, "MonitorTheme", {});
    qmlRegisterUncreatableType<MonitorViewModel>(
      registerId, 1, 0, "MonitorViewModel", {});
    qmlRegisterUncreatableType<NodeListViewModel>(
      registerId, 1, 0, "NodeListViewModel", {});

    MonitorBackend backend(ctx);
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("backend", &backend);
    engine.load("qrc:///monitor.qml");

    return app.exec();
}
//------------------------------------------------------------------------------
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::argc_copy = argc;
    eagine::argv_copy = argv;
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(MonitorExe);
    return eagine::main_impl(argc, argv, options);
}

