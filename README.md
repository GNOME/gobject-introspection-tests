# GObject Introspection Tests

This is a git submodule containing C source files.
These files are compiled into shared libraries intended for testing language
bindings for the GNOME platform. 
They are also used to test the `g-ir-scanner` tool from [gobject-introspection].

[gobject-introspection]: https://gitlab.gnome.org/GNOME/gobject-introspection

## Available modules

**Regress** test suite — a library designed as a general regression test suite,
accumulated over the lifetime of gobject-introspection.
Consists of `regress.c`, `annotation.c`, `drawable.c`, `foo.c`, and their
associated header files.

**GIMarshallingTests** suite — a library designed to exercise how every kind
of C value used in GNOME platform APIs is converted to and from native values
from the language binding.

**Utility** test suite — a library for testing external type references.

**WarnLib** test suite — a library with a number of conditions that
`g-ir-scanner` will warn about, used to test how language bindings deal with
typelibs that contain non-ideal C code.

## How to Use in a Dynamic Language Binding

Include this repository as a git submodule in your sources.

```sh
git submodule add https://gitlab.gnome.org/GNOME/gobject-introspection-tests.git
```

Add code to your build system to build the modules you want to use.
Most language bindings will want to use at least Regress and GIMarshallingTests.
Depending on how your build system is structured it might look something like
this, using GIMarshallingTests as an example:

```meson
gimarshallingtests_sources = [
    'gobject-introspection-tests/gimarshallingtests.c',
    'gobject-introspection-tests/gimarshallingtests.h',
]
libgimarshallingtests = shared_library('gimarshallingtests',
    sources: gimarshallingtests_sources,
    dependencies: [glib, gobject, gio],
    include_directories: 'gobject-introspection-tests')
gnome.generate_gir(libgimarshallingtests,
    sources: gimarshallingtests_sources,
    namespace: 'GIMarshallingTests', nsversion: '1.0',
    symbol_prefix: 'gi_marshalling_tests',
    dependencies: [glib, gobject, gio, gmodule],
    includes: ['Gio-2.0'])
```

Now you can write tests that load the GIMarshallingTests library, call each of
its functions with the expected input, and check for the expected output.
