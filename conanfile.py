from conans import ConanFile, tools, Meson
import os

class ConanFileToolsTest(ConanFile):
    generators = "pkg_config"
    requires = ["fmt/7.0.3", 'crowcpp-crow/0.3']
    settings = "os", "compiler", "build_type"

    def build(self):
        meson = Meson(self)
        # meson.configure(build_folder="build")
        meson.configure()
        meson.build()
