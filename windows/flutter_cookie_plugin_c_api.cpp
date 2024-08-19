#include "include/flutter_cookie_plugin/flutter_cookie_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "flutter_cookie_plugin.h"

void FlutterCookiePluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  flutter_cookie_plugin::FlutterCookiePlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
