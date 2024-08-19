#include "flutter_cookie_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>
#include <string>
#include <vector>
#include <memory>
#include <Shlwapi.h>
#include <WebView2.h>
#include <wil/com.h>
#include <sstream>

#pragma comment(lib, "Shlwapi.lib")



namespace flutter_cookie_plugin {

// static
void FlutterCookiePlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "flutter_cookie_plugin",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<FlutterCookiePlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

FlutterCookiePlugin::FlutterCookiePlugin() {}

FlutterCookiePlugin::~FlutterCookiePlugin() {}

    void FlutterCookiePlugin::HandleMethodCall(
            const flutter::MethodCall<flutter::EncodableValue>& method_call,
            std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
        if (method_call.method_name().compare("getCookies") == 0) {
            std::string url = std::get<std::string>(method_call.arguments());
            std::wstring wurl = std::wstring(url.begin(), url.end());

            wil::com_ptr<ICoreWebView2CookieManager> cookieManager;
            // Initialize WebView2 and get the cookieManager instance...

            std::wstring cookies = CookieHandler::GetCookies(wurl, cookieManager.get());

            result->Success(flutter::EncodableValue(std::string(cookies.begin(), cookies.end())));
        } else {
            result->NotImplemented();
        }
    }

}  // namespace flutter_cookie_plugin


class CookieHandler {
public:
    static std::wstring GetCookies(const std::wstring& url, ICoreWebView2CookieManager* cookieManager) {
        wil::com_ptr<ICoreWebView2CookieList> cookieList;
        cookieManager->GetCookies(url.c_str(), &cookieList);

        std::wstring cookieString;
        UINT cookieCount;
        cookieList->get_Count(&cookieCount);

        for (UINT i = 0; i < cookieCount; i++) {
            wil::com_ptr<ICoreWebView2Cookie> cookie;
            cookieList->GetValueAtIndex(i, &cookie);
            wil::unique_cotaskmem_string name;
            wil::unique_cotaskmem_string value;
            cookie->get_Name(&name);
            cookie->get_Value(&value);

            cookieString += name.get();
            cookieString += L"=";
            cookieString += value.get();
            cookieString += L"; ";
        }

        return cookieString;
    }
};


