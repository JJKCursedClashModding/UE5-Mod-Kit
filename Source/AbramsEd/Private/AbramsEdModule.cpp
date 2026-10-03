#include "Modules/ModuleManager.h"
#include "ISequencerModule.h"
#include "AbramsSequencerStubTrackEditor.h"

/**
 * AbramsEd module.
 *
 * Registers a generic stub track editor for all Framework-based custom sequencer tracks so the
 * modkit editor can open widget animations without asserting in FSequencer::GetTrackEditor.
 */
class FAbramsEdModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        ISequencerModule& SequencerModule = FModuleManager::LoadModuleChecked<ISequencerModule>(TEXT("Sequencer"));
        TrackEditorBindingHandle = SequencerModule.RegisterTrackEditor(
            FOnCreateTrackEditor::CreateStatic(&FAbramsSequencerStubTrackEditor::CreateTrackEditor));
    }

    virtual void ShutdownModule() override
    {
        if (FModuleManager::Get().IsModuleLoaded(TEXT("Sequencer")))
        {
            ISequencerModule& SequencerModule = FModuleManager::GetModuleChecked<ISequencerModule>(TEXT("Sequencer"));
            SequencerModule.UnRegisterTrackEditor(TrackEditorBindingHandle);
        }
    }

private:
    FDelegateHandle TrackEditorBindingHandle;
};

IMPLEMENT_MODULE(FAbramsEdModule, AbramsEd)
