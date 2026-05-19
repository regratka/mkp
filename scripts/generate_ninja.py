from ninja_syntax import Writer
from pathlib import Path
from helpers import has_functions
from project import DecompUnit

WORKSPACE_PATH = Path(__file__).parent.parent

def generateNinja(decompUnits: list[DecompUnit], output_path: Path):
    with (output_path/"build.ninja").open("w") as f:
        writer = Writer(f, width=140)     
        writer.variable("ninja_required_version", "1.5")

        for decompUnit in decompUnits:
            writer.variable(f"builddir_{decompUnit.directory_name}", str(decompUnit.buildSrc))

        writer.variable("cl", "tools\\msvc66\\Bin\\CL.exe")
        unitsImports = " ".join([f"/I {str(decUnit.includePath)}" for decUnit in decompUnits])
        for decUnit in decompUnits:
            writer.variable(f"cl_flags_{decUnit.directory_name}", f"/Zi /O2 /GR /G6 /GX /I include/ {unitsImports} /I tools/msvc66/include /I tools/dx81/include /I tools/jni /I tools/Multimedia/Common/Include /I tools /D{decUnit.directory_name.upper()}")
            writer.rule(f"cc_{decUnit.directory_name}", f"$cl /nologo $cl_flags_{decUnit.directory_name} /c $in /Fd$out.pdb /Fo$out", deps="msvc")
        
        for decompUnit in decompUnits:
            for unit, namespaces in decompUnit.units.items():
                if not has_functions(namespaces, decompUnit.mappings):
                    continue
                writer.build(f"$builddir_{decompUnit.directory_name}/" + unit + ".obj",
                            f"cc_{decompUnit.directory_name}",
                            [str(decompUnit.srcPath / (unit + ".cpp"))],
                            implicit=[str(decompUnit.includePath / (unit + ".h"))])

if __name__ == "__main__":
    generateNinja(["cVideoPlayer"], Path("build/src/me2"), Path("src/me2"), Path("include/me2"), WORKSPACE_PATH / "build.ninja")