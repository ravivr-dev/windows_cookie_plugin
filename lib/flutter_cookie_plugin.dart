
import 'flutter_cookie_plugin_platform_interface.dart';

class FlutterCookiePlugin {
  Future<String?> getPlatformVersion() {
    return FlutterCookiePluginPlatform.instance.getPlatformVersion();
  }
}
