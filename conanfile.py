from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, cmake_layout, CMakeDeps


class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    # Sources are located in the same place as this recipe, copy them to the recipe
    # exports_sources = "CMakeLists.txt", "src/*"

    def requirements(self):
        self.requires("quill/10.0.1")
        self.requires("boost/1.83.0")
        self.requires(("catch2/3.11.0"))

    def build_requirements(self):
        self.tool_requires("cmake/4.1.2")

    def layout(self):
        cmake_layout(self)
        # self.folders.build = os.path.join("build", str(self.settings.build_type))
        # self.folders.generators = os.path.join("build", str(self.settings.build_type), "generators")

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()

        tc = CMakeToolchain(self)
        # tc.user_presets_path = 'ConanPresets.json'
        tc.generate()

    # def build(self):
    #     cmake = CMake(self)
    #     cmake.configure()
    #     cmake.build()

    # def package(self):
    #     cmake = CMake(self)
    #     cmake.install()
