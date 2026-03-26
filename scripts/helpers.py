from project import Function

def has_functions(namespaces: list[str], mappings: dict[str, list[Function]]):
    for ns in namespaces:
        if ns in mappings:
            return True
    return False

def load_mappings(mappingsFile: str):
    funByNamespaces = {}
    with open(mappingsFile) as mapping_f:
        for csvLine in mapping_f.read().splitlines():
            function = Function.create(csvLine)
            ns = function.namespace
            if ns in funByNamespaces:
                funByNamespaces[ns].append(function)
            else:
                funByNamespaces[ns] = [function]
    return funByNamespaces
    

def load_units(unitsPath: str):
    namespacesByUnit = {}
    with open(unitsPath) as units_f:
        for unitLine in units_f.read().splitlines():
            unitParts = unitLine.split(',')
            unitName = unitParts[0]
            unitNamespaces = unitParts[1:]
            namespacesByUnit[unitName] = unitNamespaces
    return namespacesByUnit

def load_completed(completePath: str):
    completed  = set()
    with open(completePath) as complete_f:
        for line in complete_f.read().splitlines():
            completed.add(line)
    return completed
