import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'flutter_cookie_plugin_platform_interface.dart';

/// An implementation of [FlutterCookiePluginPlatform] that uses method channels.
class MethodChannelFlutterCookiePlugin extends FlutterCookiePluginPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('flutter_cookie_plugin');

  @override
  Future<String?> getCookies(String url) async {
    final String cookies = await methodChannel.invokeMethod('getCookies', url);
    return cookies;
  }
}
