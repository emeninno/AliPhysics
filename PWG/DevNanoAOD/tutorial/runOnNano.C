void runOnNano()
{
  AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();
  if (!mgr) mgr = new AliAnalysisManager("train");

  AliAODInputHandler* iH = new AliAODInputHandler();
  mgr->SetInputEventHandler(iH);

  AliAnalysisTaskSE* task = (AliAnalysisTaskSE*) gInterpreter->ExecuteMacro("$ALICE_PHYSICS/PWG/DevNanoAOD/tutorial/AddTaskSimple.C");
  task->SelectCollisionCandidates(AliVEvent::kINT7);
  
  mgr->InitAnalysis();
  mgr->PrintStatus();
  
  // Create chain of input files
  TChain * chain = new TChain("aodTree");
  chain->Add("AliAOD.NanoAOD.root");

  TStopwatch watch;
  mgr->StartAnalysis("local", chain, 1000);
  watch.Print();
}
