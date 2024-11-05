from conan import ConanFile

class GuideMyRideRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("poco/1.13.3")
        self.requires("grpc/1.67.1")
        self.requires("argon2/20190702")
        
        self.test_requires("gtest/1.15.0")

    def configure(self):
        poco = self.options["poco/*"]
        grpc = self.options["grpc/*"]

        # POCO options
        poco.fPIC = True
        poco.enable_net = True
        poco.enable_xml = True
        poco.enable_util = True
        poco.enable_data = True
        poco.enable_data_postgresql = True
        poco.enable_redis = True
        poco.enable_activerecord = True

        poco.shared = False
        poco.enable_jwt = False
        poco.enable_zip = False
        poco.enable_json = False
        poco.enable_crypto = False
        poco.enable_netssl = False
        poco.enable_mongodb = False
        poco.enable_data_mysql = False
        poco.enable_data_sqlite = False

        # gRPC options
        grpc.fPIC = True
        grpc.cpp_plugin = True

        grpc.shared = False
        grpc.php_plugin = False
        grpc.node_plugin = False
        grpc.ruby_plugin = False
        grpc.csharp_plugin = False
        grpc.python_plugin = False
        grpc.with_libsystemd = False
        grpc.objective_c_plugin = False

    def layout(self):
        cmake_layout(self) 
