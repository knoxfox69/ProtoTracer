#include "Examples/Templates/ProtogenProjectTemplate.h"
#include "Assets/Models/FBX/RhaskyProtoV3CustomExpression.h"
#include "Assets/Models/OBJ/DeltaDisplayBackground.h"
#include "Camera/CameraManager/Implementations/HUB75DeltaCameras.h"
#include "Controller/HUB75Controller.h"

class RhaskyProtogenV3 : public ProtogenProject {
private:
    HUB75DeltaCameraManager cameras;
    HUB75Controller controller = HUB75Controller(&cameras, 50, 50);
    RhaskyProtoV3CustomExpression faceModel;
    DeltaDisplayBackground deltaDisplayBackground;
    
    const __FlashStringHelper* faceArray[8] = {
        F("DEFAULT"), F("ANGRY"), F("SAD"), F("HAPPY"), 
        F("SURPRISED"), F("FOCUSED"), F("BLINK"), F("CUSTOM")
    };

    // Model Configuration Constants - Adjust these for proper alignment
    static constexpr float MODEL_OFFSET_X = 96.0f;    // Horizontal offset (center screen)
    static constexpr float MODEL_OFFSET_Y = 47.0f;    // Vertical offset (center screen)
    static constexpr float MODEL_OFFSET_Z = -7.5f;    // Depth offset for face alignment
    static constexpr float MODEL_SCALE    = 1.0f;     // Model scaling factor
    static constexpr float MODEL_ROT_X    = 0.0f;     // Pitch (up/down)
    static constexpr float MODEL_ROT_Y    = 180.0f;   // Yaw (left/right) - FIX: model facing backwards!
    static constexpr float MODEL_ROT_Z    = 0.0f;     // Roll (clockwise/counter)

    // Runtime transform values
    Vector3D modelPosition;
    Vector3D modelRotation;
    float    modelScale;

    void LinkControlParameters() override {
        // Link morph weights to animation parameters
        AddParameter(RhaskyProtoV3CustomExpression::AddEyebrow, faceModel.GetMorphWeightReference(RhaskyProtoV3CustomExpression::AddEyebrow), 15);
        AddParameter(RhaskyProtoV3CustomExpression::MouthFrown, faceModel.GetMorphWeightReference(RhaskyProtoV3CustomExpression::MouthFrown), 15);
        AddParameter(RhaskyProtoV3CustomExpression::EyeFrown, faceModel.GetMorphWeightReference(RhaskyProtoV3CustomExpression::EyeFrown), 15);
        AddParameter(RhaskyProtoV3CustomExpression::HappySquint, faceModel.GetMorphWeightReference(RhaskyProtoV3CustomExpression::HappySquint), 15);
        AddParameter(RhaskyProtoV3CustomExpression::AngryEyes, faceModel.GetMorphWeightReference(RhaskyProtoV3CustomExpression::AngryEyes), 15);
        
        // Add blink parameter
        AddBlinkParameter(faceModel.GetMorphWeightReference(RhaskyProtoV3CustomExpression::EyeFrown));
    }

    void Default() {
        // Reset all morphs to neutral
        faceModel.Reset();
    }
    
    void Angry() {
        AddParameterFrame(RhaskyProtoV3CustomExpression::AngryEyes, 1.0f);
        AddParameterFrame(RhaskyProtoV3CustomExpression::EyeFrown, 0.8f);
        AddMaterialFrame(Color::CRED);
    }
    
    void Happy() {
        AddParameterFrame(RhaskyProtoV3CustomExpression::HappySquint, 1.0f);
        AddMaterialFrame(Color::CYELLOW);
    }
    
    void Sad() {
        AddParameterFrame(RhaskyProtoV3CustomExpression::MouthFrown, 1.0f);
        AddParameterFrame(RhaskyProtoV3CustomExpression::EyeFrown, 0.6f);
        AddMaterialFrame(Color::CBLUE);
    }
    
    void Surprised() {
        AddParameterFrame(RhaskyProtoV3CustomExpression::AddEyebrow, 0.8f);
        AddParameterFrame(RhaskyProtoV3CustomExpression::HappySquint, 0.5f);
        AddMaterialFrame(Color::CRAINBOW);
    }
    
    void Focused() {
        AddParameterFrame(RhaskyProtoV3CustomExpression::EyeFrown, 0.7f);
        AddParameterFrame(RhaskyProtoV3CustomExpression::AngryEyes, 0.3f);
        AddMaterialFrame(Color::CWHITE);
    }
    
    void Blink() {
        AddParameterFrame(RhaskyProtoV3CustomExpression::EyeFrown, 1.0f);
        AddMaterialFrame(Color::CBLACK);
    }

public:
    RhaskyProtogenV3() : ProtogenProject(&cameras, &controller, 2, Vector2D(), Vector2D(192.0f, 94.0f), 22, 23, 8) {
        // Initialize transform values from configuration constants
        modelPosition = Vector3D(MODEL_OFFSET_X, MODEL_OFFSET_Y, MODEL_OFFSET_Z);
        modelRotation = Vector3D(MODEL_ROT_X, MODEL_ROT_Y, MODEL_ROT_Z);
        modelScale    = MODEL_SCALE;

        scene.AddObject(faceModel.GetObject());
        scene.AddObject(deltaDisplayBackground.GetObject());

        faceModel.GetObject()->SetMaterial(GetFaceMaterial());
        deltaDisplayBackground.GetObject()->SetMaterial(GetFaceMaterial());

        // Apply base transform once during initialization
        faceModel.GetObject()->GetTransform()->SetRotation(modelRotation);
        faceModel.GetObject()->GetTransform()->SetScale(Vector3D(modelScale, modelScale, modelScale));

        hud.SetFaceArray(faceArray);
        LinkControlParameters();
        
        SetWiggleSpeed(5.0f);
        SetMenuOffset(Vector2D(17.5f, -3.0f));
        SetMenuSize(Vector2D(192, 56));
    }

    void Update(float ratio) override {
        faceModel.Reset();
        
        uint8_t mode = Menu::GetFaceState();
        controller.SetBrightness(Menu::GetBrightness());
        controller.SetAccentBrightness(Menu::GetAccentBrightness());

        SelectFace(mode);
        UpdateFace(ratio);
        faceModel.Update();
        
        // Calculate final position (base offset + wiggle animation)
        Vector3D finalPosition = modelPosition + GetWiggleOffset();
        
        // Apply clean transform chain
        faceModel.GetObject()->GetTransform()->SetPosition(finalPosition);
        
        // Background should remain static
        deltaDisplayBackground.GetObject()->GetTransform()->SetPosition(modelPosition);
    }

    void SelectFace(uint8_t code) {
        switch(code) {
            case 0: Default();  break;
            case 1: Angry();    break;
            case 2: Sad();      break;
            case 3: Happy();    break;
            case 4: Surprised(); break;
            case 5: Focused();  break;
            case 6: Blink();    break;
            default: AudioReactiveGradientFace(); break;
        }
    }

    // Pure virtual function implementations required by ProtogenProject
    void SpectrumAnalyzerCallback() override {
        AddMaterialFrame(Color::CHORIZONTALRAINBOW, 0.8f);
    }

    void AudioReactiveGradientCallback() override {
        AddMaterialFrame(Color::CHORIZONTALRAINBOW, 0.8f);
    }

    void OscilloscopeCallback() override {
        AddMaterialFrame(Color::CHORIZONTALRAINBOW, 0.8f);
    }

    // -------------------------------------------------------------------------
    // Public Configuration API - Runtime adjustment for testing & calibration
    // -------------------------------------------------------------------------
    void SetModelPosition(const Vector3D& newPosition) {
        modelPosition = newPosition;
    }

    void SetModelRotation(float x, float y, float z) {
        modelRotation = Vector3D(x, y, z);
        faceModel.GetObject()->GetTransform()->SetRotation(modelRotation);
    }

    void SetModelScale(float newScale) {
        modelScale = newScale;
        faceModel.GetObject()->GetTransform()->SetScale(Vector3D(modelScale, modelScale, modelScale));
    }

    void SetModelOffsetX(float x) { modelPosition.X = x; }
    void SetModelOffsetY(float y) { modelPosition.Y = y; }
    void SetModelOffsetZ(float z) { modelPosition.Z = z; }

    // Getters for debugging
    Vector3D GetModelPosition() const { return modelPosition; }
    Vector3D GetModelRotation() const { return modelRotation; }
    float    GetModelScale()    const { return modelScale; }
};
