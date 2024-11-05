from conan import ConanFile

class GuideMyRideRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("poco/1.13.3")
        self.requires("grpc/1.67.1")
        self.requires("argon2/20190702")
        
        self.test_requires("gtest/1.15.0")
    def layout(self):
        cmake_layout(self) 
