##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=benchmarkIoTGUI
ConfigurationName      :=Debug
WorkspacePath          :=/home/vslavk/workspace/gdevProjects/gdevWorkspace
ProjectPath            :=/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Viacheslav Kulik
Date                   :=16.08.2017
CodeLitePath           :=/home/vslavk/.codelite
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)__WX__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="benchmarkIoTGUI.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell wx-config   --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/gui.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/IoTThread.cpp$(ObjectSuffix) $(IntermediateDirectory)/callBenchmark.cpp$(ObjectSuffix) $(IntermediateDirectory)/controlIoTThreads.cpp$(ObjectSuffix) $(IntermediateDirectory)/generateRandomNumbers.cpp$(ObjectSuffix) $(IntermediateDirectory)/sendThingMessages.cpp$(ObjectSuffix) $(IntermediateDirectory)/uniqueThing.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/gui.cpp$(ObjectSuffix): gui.cpp $(IntermediateDirectory)/gui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI/gui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui.cpp$(DependSuffix): gui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui.cpp$(DependSuffix) -MM gui.cpp

$(IntermediateDirectory)/gui.cpp$(PreprocessSuffix): gui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui.cpp$(PreprocessSuffix) gui.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/IoTThread.cpp$(ObjectSuffix): IoTThread.cpp $(IntermediateDirectory)/IoTThread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI/IoTThread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IoTThread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IoTThread.cpp$(DependSuffix): IoTThread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IoTThread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IoTThread.cpp$(DependSuffix) -MM IoTThread.cpp

$(IntermediateDirectory)/IoTThread.cpp$(PreprocessSuffix): IoTThread.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IoTThread.cpp$(PreprocessSuffix) IoTThread.cpp

$(IntermediateDirectory)/callBenchmark.cpp$(ObjectSuffix): callBenchmark.cpp $(IntermediateDirectory)/callBenchmark.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI/callBenchmark.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/callBenchmark.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/callBenchmark.cpp$(DependSuffix): callBenchmark.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/callBenchmark.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/callBenchmark.cpp$(DependSuffix) -MM callBenchmark.cpp

$(IntermediateDirectory)/callBenchmark.cpp$(PreprocessSuffix): callBenchmark.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/callBenchmark.cpp$(PreprocessSuffix) callBenchmark.cpp

$(IntermediateDirectory)/controlIoTThreads.cpp$(ObjectSuffix): controlIoTThreads.cpp $(IntermediateDirectory)/controlIoTThreads.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI/controlIoTThreads.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/controlIoTThreads.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/controlIoTThreads.cpp$(DependSuffix): controlIoTThreads.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/controlIoTThreads.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/controlIoTThreads.cpp$(DependSuffix) -MM controlIoTThreads.cpp

$(IntermediateDirectory)/controlIoTThreads.cpp$(PreprocessSuffix): controlIoTThreads.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/controlIoTThreads.cpp$(PreprocessSuffix) controlIoTThreads.cpp

$(IntermediateDirectory)/generateRandomNumbers.cpp$(ObjectSuffix): generateRandomNumbers.cpp $(IntermediateDirectory)/generateRandomNumbers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI/generateRandomNumbers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/generateRandomNumbers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/generateRandomNumbers.cpp$(DependSuffix): generateRandomNumbers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/generateRandomNumbers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/generateRandomNumbers.cpp$(DependSuffix) -MM generateRandomNumbers.cpp

$(IntermediateDirectory)/generateRandomNumbers.cpp$(PreprocessSuffix): generateRandomNumbers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/generateRandomNumbers.cpp$(PreprocessSuffix) generateRandomNumbers.cpp

$(IntermediateDirectory)/sendThingMessages.cpp$(ObjectSuffix): sendThingMessages.cpp $(IntermediateDirectory)/sendThingMessages.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI/sendThingMessages.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sendThingMessages.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sendThingMessages.cpp$(DependSuffix): sendThingMessages.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sendThingMessages.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sendThingMessages.cpp$(DependSuffix) -MM sendThingMessages.cpp

$(IntermediateDirectory)/sendThingMessages.cpp$(PreprocessSuffix): sendThingMessages.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sendThingMessages.cpp$(PreprocessSuffix) sendThingMessages.cpp

$(IntermediateDirectory)/uniqueThing.cpp$(ObjectSuffix): uniqueThing.cpp $(IntermediateDirectory)/uniqueThing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vslavk/workspace/purec_cpp/generateIoTTrafficGUI/uniqueThing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/uniqueThing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/uniqueThing.cpp$(DependSuffix): uniqueThing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/uniqueThing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/uniqueThing.cpp$(DependSuffix) -MM uniqueThing.cpp

$(IntermediateDirectory)/uniqueThing.cpp$(PreprocessSuffix): uniqueThing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/uniqueThing.cpp$(PreprocessSuffix) uniqueThing.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


