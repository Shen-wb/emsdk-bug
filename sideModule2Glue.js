function SideModuleTwo(name, birthday) {
    ensureCache.prepare();
    if (name && typeof name === 'object') name = name.ptr;
    else name = ensureString(name);
    if (birthday && typeof birthday === 'object') birthday = birthday.ptr;
    else birthday = ensureString(birthday);
    this.ptr = Module._emscripten_bind_SideModuleTwo_SideModule_2(name, birthday);
    getCache(SideModuleTwo)[this.ptr] = this;
}
SideModuleTwo.prototype = Object.create(WrapperObject.prototype);
SideModuleTwo.prototype.constructor = SideModuleTwo;
SideModuleTwo.prototype.__class__ = SideModuleTwo;
SideModuleTwo.__cache__ = {};
Module['SideModuleTwo'] = SideModuleTwo;

SideModuleTwo.prototype['getInfo'] = SideModuleTwo.prototype.getInfo = function() {
    var self = this.ptr;
    return UTF8ToString(Module._emscripten_bind_SideModuleTwo_getInfo_0(self));
};

SideModuleTwo.prototype['generateRandomString'] = SideModuleTwo.prototype.generateRandomString = function(len) {
    var self = this.ptr;
    return UTF8ToString(Module._emscripten_bind_SideModuleTwo_generateRandomString_1(self, len));
};