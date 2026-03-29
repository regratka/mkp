from ninja_syntax import Writer
from pathlib import Path
from helpers import has_functions

WORKSPACE_PATH = Path(__file__).parent.parent

def generateNinja(units: dict[str, list[str]], mappings: dict[str, object], build_dir: Path, src_dir: Path, include_dir: Path, output_path: Path):
    with (output_path/"build.ninja").open("w") as f:
        writer = Writer(f, width=140)     
        writer.variable("ninja_required_version", "1.5")
        writer.variable("builddir", str(build_dir))
        writer.variable("cl", "tools\\msvc66\\Bin\\CL.exe")
        writer.variable("cl_flags", f"/Zi /O2 /GR /G6 /GX /I include/ /I {str(include_dir)} /I tools/msvc66/include /I tools/dx81/include /I tools/Multimedia/Common/Include")

        writer.rule("cc", "$cl /nologo $cl_flags /c $in /Fd$out.pdb /Fo$out", deps="msvc")
        
        for unit, namespaces in units.items():
            if not has_functions(namespaces, mappings):
                continue
            writer.build("$builddir/" + unit + ".obj",
                         "cc",
                         [str(src_dir /(unit + ".cpp"))],
                         implicit=[str(include_dir /(unit + ".h"))])
        writer.close()

if __name__ == "__main__":
    generateNinja(["cVideoPlayer"], Path("build/src/me2"), Path("src/me2"), Path("include/me2"), WORKSPACE_PATH / "build.ninja")