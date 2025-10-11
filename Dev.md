bazel prefer system lib over project lib, you have to explicit pointout using --cxxopt=-Iexternal/boost+
https://bazel.build/versions/6.0.0/rules/lib/globals#archive_override
https://bazel.build/reference/be/c-cpp#cc_library