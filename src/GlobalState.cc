#include <BA.hh>
#include <BA/Vector3.hh>
#include <BA/GlobalState.hh>
#include <BA/Scene.hh>
#include <BA/GlutCallbacks.hh>
#include <BA/RenderObject.hh>
#include <BA/TeapotObject.hh>
#include <iostream>

namespace BA {
  GlobalState::GlobalState() {
    camera = new Vector3<float>(0.0f, 0.0f, 0.0f);
    light = new Vector3<float>(0.0f, 0.0f, 0.0f);
  }

  GlobalState::~GlobalState() {
    delete camera;
    delete light;
  }

  bool GlobalState::hasAmbient() {
    return ambient;
  }

  void GlobalState::setAmbient(bool _ambient) {
    ambient = _ambient;
  }

  bool GlobalState::hasDiffuse() {
    return diffuse;
  }

  void GlobalState::setDiffuse(bool _diffuse) {
    diffuse = _diffuse;
  }

  bool GlobalState::hasSpecular() {
    return specular;
  }

  void GlobalState::setSpecular(bool _specular) {
    specular = _specular;
  }

  uint GlobalState::getShader() {
    return shader;
  }

  void GlobalState::setShader(uint _shader) {
    shader = _shader;
  }

  uint GlobalState::getTexture() {
    return texture;
  }

  void GlobalState::setTexture(uint _texture) {
    texture = _texture;
  }

  uint GlobalState::getFbo() {
    return fbo;
  }

  void GlobalState::setFbo(uint _fbo) {
    fbo = _fbo;
  }

  Vector3<float> *GlobalState::getCamera() {
    return camera;
  }

  Vector3<float> *GlobalState::getLight() {
    return light;
  }

  void GlobalState::setCamera(float _x, float _y, float _z) {
    camera->x = _x;
    camera->y = _y;
    camera->z = _z;
  }

  void GlobalState::setLight(float _x, float _y, float _z) {
    light->x = _x;
    light->y = _y;
    light->z = _z;
  }

  void GlobalState::setName(string _name) {
    name = _name;
  }

  int GlobalState::getStateType() {
    return stateType;
  }

  void GlobalState::setStateType(int _stateType) {
    stateType = _stateType;
  }

  string GlobalState::toString() {
    return name;
  }
}

