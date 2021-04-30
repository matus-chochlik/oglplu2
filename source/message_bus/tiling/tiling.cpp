#include "TilingBackend.hpp"
#include <eagine/main_ctx.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <clocale>

namespace eagine {
//------------------------------------------------------------------------------
int argc_copy = 0;
const char** argv_copy = nullptr;
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    ctx.log().info("message bus tiling starting");

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app{argc_copy, const_cast<char**>(argv_copy)};
    std::setlocale(LC_NUMERIC, "C");

    const auto registerId = "com.github.matus-chochlik.oglplu2";

    qmlRegisterUncreatableType<TilingTheme>(
      registerId, 1, 0, "TilingTheme", {});

    TilingBackend backend(ctx);
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("backend", &backend);
    engine.load("qrc:///tiling.qml");

    return app.exec();
}
//------------------------------------------------------------------------------
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::argc_copy = argc;
    eagine::argv_copy = argv;
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(TilingExe);
    return eagine::main_impl(argc, argv, options);
}

