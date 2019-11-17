#pragma once

#include <windows.h>
#include <vcclr.h>
#using <System.dll>
#using <System.Drawing.dll>
#include <string>
#include <array>

using namespace System;
using namespace System::Drawing;
using namespace std;

namespace Aipu2NetLib {

	class UnmanagedAipu
	{
	public:
		UnmanagedAipu();
		~UnmanagedAipu();
		LPCWSTR GetError();
		LPCWSTR GetUser();
		void InitLibrary();
		void LoadConfiguration(LPCWSTR nameFile);
		void SetIsRegister(bool option);
		void SetFileVideo(LPCWSTR file);
		void SetNameWindow(LPCWSTR name);
		void SetWidthFrame(int value);
		void SetHeightFrame(int value);
		void CaptureFlow(int optionFlow);
		void SetIpCamera(LPCWSTR ip);
		void SetFaceConfidenceThresh(int value);
		void SetRefreshInterval(int value);
		void SetMinEyeDistance(int minDistance);
		void SetMaxEyeDistance(int maxDistance);
		void SetSequenceFps(int fps);
		void SetClient(int value);
		void SetFlagFlow(bool flag);
		void Terminate();
		void ReloadRecognitionFace();
		void SetConfigurationDatabase();
		void ShowWindow(int option);
		void SetIsFinishLoadFiles(bool value);
		bool GetIsFinishLoadFiles();
		void RecognitionFaceFiles(LPCWSTR file, int client);
	private:

	};

	
	public ref class AipuNet
	{
	public:
		AipuNet();
		~AipuNet();
		property System::String ^  GetError {
			System::String ^ get() {
				return gcnew System::String(implementAipu->GetError());
			}
		}

		property System::String ^  GetUser {
			System::String ^ get() {
				return gcnew System::String(implementAipu->GetUser());
			}
		}

		property System::Boolean GetIsFinishLoadFiles {
			System::Boolean get() {
				return implementAipu->GetIsFinishLoadFiles();
			}
		}

		void InitLibrary();

		void LoadConfiguration(System::String ^ fileString);
		void SetIsRegister(System::Boolean option);
		void SetFileVideo(System::String ^ file);
		void SetNameWindow(System::String ^ name);
		void SetWidthFrame(System::Int32 value);
		void SetHeightFrame(System::Int32 value);
		void CaptureFlow(System::Int32 optionFlow);
		void SetIpCamera(System::String ^ ip);
		void SetFaceConfidenceThresh(System::Int32 value);
		void SetRefreshInterval(System::Int32 value);
		void SetMinEyeDistance(System::Int32 minDistance);
		void SetMaxEyeDistance(System::Int32 maxDistance);
		void SetSequenceFps(System::Int32 fps);
		void SetClient(System::Int32 value);
		void SetFlagFlow(System::Boolean flag);
		void Terminate();
		void ReloadRecognitionFace();
		void SetConfigurationDatabase();
		void ShowWindow(System::Int32 option);
		void SetIsFinishLoadFiles(System::Boolean value);
		void RecognitionFaceFiles(System::String ^ file, System::Int32 client);

	protected:
		!AipuNet() {
			delete implementAipu;
		}
	private:
		UnmanagedAipu* implementAipu;
	};
}
