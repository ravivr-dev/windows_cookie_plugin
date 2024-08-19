import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'flutter_cookie_plugin_method_channel.dart';

abstract class FlutterCookiePluginPlatform extends PlatformInterface {
  /// Constructs a FlutterCookiePluginPlatform.
  FlutterCookiePluginPlatform() : super(token: _token);

  static final Object _token = Object();

  static FlutterCookiePluginPlatform _instance = MethodChannelFlutterCookiePlugin();

  /// The default instance of [FlutterCookiePluginPlatform] to use.
  ///
  /// Defaults to [MethodChannelFlutterCookiePlugin].
  static FlutterCookiePluginPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FlutterCookiePluginPlatform] when
  /// they register themselves.
  static set instance(FlutterCookiePluginPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }


  Future<String?> getCookies(String url) async {
    final String? cookies = await _instance.getCookies(url);
    return cookies;
  }



}
