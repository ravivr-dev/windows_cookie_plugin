import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_cookie_plugin/flutter_cookie_plugin.dart';
import 'package:flutter_cookie_plugin/flutter_cookie_plugin_platform_interface.dart';
import 'package:flutter_cookie_plugin/flutter_cookie_plugin_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockFlutterCookiePluginPlatform
    with MockPlatformInterfaceMixin
    implements FlutterCookiePluginPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');

  @override
  Future<String?> getCookies(String url) {
    // TODO: implement getCookies
    throw UnimplementedError();
  }
}

void main() {
  final FlutterCookiePluginPlatform initialPlatform = FlutterCookiePluginPlatform.instance;

  test('$MethodChannelFlutterCookiePlugin is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelFlutterCookiePlugin>());
  });

  test('getPlatformVersion', () async {
    FlutterCookiePlugin flutterCookiePlugin = FlutterCookiePlugin();
    MockFlutterCookiePluginPlatform fakePlatform = MockFlutterCookiePluginPlatform();
    FlutterCookiePluginPlatform.instance = fakePlatform;

    expect(await flutterCookiePlugin.getCookies(""), '42');
    
  });
}
