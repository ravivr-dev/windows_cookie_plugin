
import 'flutter_cookie_plugin_platform_interface.dart';

class FlutterCookiePlugin {
  Future<String?> getCookies(String url) {
    return FlutterCookiePluginPlatform.instance.getCookies(url);
  }
}
