#pragma once

#include "TestResult.h"

#include "llvm/ExecutionEngine/Orc/ObjectLinkingLayer.h"
#include "llvm/IR/Mangler.h"
#include "llvm/Object/Binary.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class Function;
class Module;

}

namespace Mutang {

class Test;

class SimpleTestRunner {
  llvm::orc::ObjectLinkingLayer<> ObjectLayer;
  std::unique_ptr<llvm::TargetMachine> TM;
  llvm::Mangler Mangler;
public:

  /// FIXME: these are need to be removed from here
  typedef std::vector<llvm::object::ObjectFile *> ObjectFiles;
  typedef std::vector<llvm::object::OwningBinary<llvm::object::ObjectFile>> OwnedObjectFiles;

  SimpleTestRunner();
  ExecutionResult runTest(Test *Test, ObjectFiles &ObjectFiles);

private:
  std::string MangleName(const llvm::StringRef &Name);
  void *TestFunctionPointer(const llvm::Function &Function);
};

}
