Pod::Spec.new do |spec|
  spec.name         = "IVoiceSDK"
  spec.version      = "1.1.0"
  spec.summary      = "iVoiceSDK"
  spec.description  = "Corpize iVoiceSDK for iOS."
  spec.homepage     = "https://github.com/Hexyz/iVoiceSDK"
  spec.license      = { :type => 'Copyright', :text => "Coripze copyright" }
  spec.author       = { "𓄅 ᕼ Ξ Ⅹ 〒 Ƶ" => "hi@hexyz.cn" }
  spec.platform     = :ios, "10.0"
  spec.ios.deployment_target = "10.0"
  spec.source       = { :git => "https://github.com/Hexyz/iVoiceSDK.git", :tag => "#{spec.version}"}
  spec.resources    = "Frameworks/iVoiceSDK.bundle"
  spec.source_files = "Frameworks/iVoiceSDK.framework/Headers", "*.{h,m}"
  spec.vendored_frameworks = "Frameworks/**/*.{framework}"
  spec.requires_arc = true
  spec.pod_target_xcconfig = {'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.dependency 'MJExtension'
  spec.dependency 'SDWebImage'
  spec.dependency 'Toast'
end
