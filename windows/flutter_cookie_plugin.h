#ifndef FLUTTER_PLUGIN_FLUTTER_COOKIE_PLUGIN_H_
#define FLUTTER_PLUGIN_FLUTTER_COOKIE_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace flutter_cookie_plugin {

class FlutterCookiePlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  FlutterCookiePlugin();

  virtual ~FlutterCookiePlugin();

  // Disallow copy and assign.
  FlutterCookiePlugin(const FlutterCookiePlugin&) = delete;
  FlutterCookiePlugin& operator=(const FlutterCookiePlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace flutter_cookie_plugin

#endif  // FLUTTER_PLUGIN_FLUTTER_COOKIE_PLUGIN_H_
