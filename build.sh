#for ios
gyp secure_sqlite3.gyp --depth=. -f xcode -DOS=ios --generator-output=./proj.ios/
xcodebuild -project proj.ios/secure_sqlite3.xcodeproj
# mv ./build/Default-iphoneos/libsqlite3.a ./
# rm -rf ./build
# rm -rf secure_sqlite3.xcodeproj

#for mac
gyp secure_sqlite3.gyp --depth=. -DOS=mac --generator-output=./proj.mac/
xcodebuild -project proj.mac/secure_sqlite3.xcodeproj
# mv ./build/Default/* ./
# rm -rf ./build
# rm -rf secure_sqlite3.xcodeproj