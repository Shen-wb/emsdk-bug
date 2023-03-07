function SideModule(name, birthday) {
    ensureCache.prepare();
    if (name && typeof name === 'object') name = name.ptr;
    else name = ensureString(name);
    if (birthday && typeof birthday === 'object') birthday = birthday.ptr;
    else birthday = ensureString(birthday);
    this.ptr = Module._emscripten_bind_SideModule_SideModule_2(name, birthday);getInfo
    getCache(SideModule)[this.ptr] = this;
}
SideModule.prototype = Object.create(WrapperObject.prototype);
SideModule.prototype.constructor = SideModule;
SideModule.prototype.__class__ = SideModule;
SideModule.__cache__ = {};
Module['SideModule'] = SideModule;

SideModule.prototype['getInfo'] = SideModule.prototype.getInfo = function() {
    var self = this.ptr;
    return UTF8ToString(Module._emscripten_bind_SideModule_getInfo_0(self));
};

SideModule.prototype['fb'] = SideModule.prototype.fb = function(n) {
    var self = this.ptr;
    return Module._emscripten_bind_SideModule_fb_1(self, n);
};