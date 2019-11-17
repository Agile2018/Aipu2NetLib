#include "stdafx.h"

#include "Aipu2NetLib.h"
#include <AipuAPI.h>

using namespace Aipu2NetLib;

AipuAPI* aipuApi;

AipuNet::AipuNet() {
	implementAipu = new UnmanagedAipu();
}

AipuNet::~AipuNet() {
	delete implementAipu;
}

void AipuNet::LoadConfiguration(System::String ^ fileString) {
	pin_ptr<const WCHAR> fileConfig = PtrToStringChars(fileString);
	implementAipu->LoadConfiguration(fileConfig);

}

void AipuNet::InitLibrary() {
	implementAipu->InitLibrary();
}

void AipuNet::SetIsRegister(System::Boolean option) {
	if (option.Equals(true))
	{
		implementAipu->SetIsRegister(true);
	}
	else {
		implementAipu->SetIsRegister(false);
	}

}

void AipuNet::SetFileVideo(System::String ^ file) {
	pin_ptr<const WCHAR> fileConfig = PtrToStringChars(file);
	implementAipu->SetFileVideo(fileConfig);
}

void AipuNet::SetWidthFrame(System::Int32 value) {
	implementAipu->SetWidthFrame(value);
}

void AipuNet::SetHeightFrame(System::Int32 value) {
	implementAipu->SetHeightFrame(value);
}

void AipuNet::CaptureFlow(System::Int32 optionFlow) {
	implementAipu->CaptureFlow(optionFlow);
}

void AipuNet::SetIpCamera(System::String ^ ip) {
	pin_ptr<const WCHAR> address = PtrToStringChars(ip);
	implementAipu->SetIpCamera(address);
}

void AipuNet::SetNameWindow(System::String ^ name) {
	pin_ptr<const WCHAR> nameWindow = PtrToStringChars(name);
	implementAipu->SetNameWindow(nameWindow);
}

void AipuNet::SetFaceConfidenceThresh(System::Int32 value) {
	implementAipu->SetFaceConfidenceThresh(value);
}

void AipuNet::SetRefreshInterval(System::Int32 value) {
	implementAipu->SetRefreshInterval(value);
}

void AipuNet::SetMinEyeDistance(System::Int32 minDistance) {
	implementAipu->SetMinEyeDistance(minDistance);
}

void AipuNet::SetMaxEyeDistance(System::Int32 maxDistance) {
	implementAipu->SetMaxEyeDistance(maxDistance);
}

void AipuNet::SetSequenceFps(System::Int32 fps) {
	implementAipu->SetSequenceFps(fps);
}

void AipuNet::SetClient(System::Int32 value) {
	implementAipu->SetClient(value);
}

void AipuNet::SetFlagFlow(System::Boolean flag) {
	if (flag.Equals(true))
	{
		implementAipu->SetFlagFlow(true);
	}
	else {
		implementAipu->SetFlagFlow(false);
	}
}

void AipuNet::Terminate() {
	implementAipu->Terminate();
}

void AipuNet::ReloadRecognitionFace() {
	implementAipu->ReloadRecognitionFace();
}

void AipuNet::SetConfigurationDatabase() {
	implementAipu->SetConfigurationDatabase();
}

void AipuNet::ShowWindow(System::Int32 option) {
	implementAipu->ShowWindow(option);
}

void AipuNet::SetIsFinishLoadFiles(System::Boolean value) {
	if (value.Equals(true))
	{
		implementAipu->SetIsFinishLoadFiles(true);
	}
	else {
		implementAipu->SetIsFinishLoadFiles(false);
	}
	
}

void AipuNet::RecognitionFaceFiles(System::String ^ file, System::Int32 client) {
	pin_ptr<const WCHAR> fileFace = PtrToStringChars(file);
	implementAipu->RecognitionFaceFiles(fileFace, client);
	
}

UnmanagedAipu::UnmanagedAipu()
{
	aipuApi = new AipuAPI();
}

UnmanagedAipu::~UnmanagedAipu()
{
	delete aipuApi;
}

LPCWSTR UnmanagedAipu::GetError() {
	string messageReceived = aipuApi->GetMessageError();
	wstring wideMessage(messageReceived.begin(), messageReceived.end());
	const wchar_t* resultMessage = wideMessage.c_str();
	return resultMessage;
}

LPCWSTR UnmanagedAipu::GetUser() {
	string user = aipuApi->GetUserJSON();
	wstring wideUser(user.begin(), user.end());
	const wchar_t* resultUser = wideUser.c_str();	
	return resultUser;

}

void UnmanagedAipu::InitLibrary() {
	aipuApi->InitLibrary();
}

void UnmanagedAipu::LoadConfiguration(LPCWSTR nameFile) {
	wstring lpcwstrToWstring(nameFile);
	string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());
	aipuApi->LoadConfiguration(wStringToString);

}

void UnmanagedAipu::RecognitionFaceFiles(LPCWSTR file, int client) {
	
	wstring lpcwstrToWstring(file);
	string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());	
	aipuApi->RecognitionFaceFiles(wStringToString, client);
}

void UnmanagedAipu::SetIsRegister(bool option) {
	aipuApi->SetIsRegister(option);
}

void UnmanagedAipu::SetFileVideo(LPCWSTR file) {
	wstring lpcwstrToWstring(file);
	string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());
	aipuApi->SetFileVideo(wStringToString);
}

void UnmanagedAipu::SetNameWindow(LPCWSTR name) {
	wstring lpcwstrToWstring(name);
	string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());
	aipuApi->SetNameWindow(wStringToString);
}

void UnmanagedAipu::SetWidthFrame(int value) {
	aipuApi->SetWidthFrame(value);
}

void UnmanagedAipu::SetHeightFrame(int value) {
	aipuApi->SetHeightFrame(value);
}


void UnmanagedAipu::CaptureFlow(int optionFlow) {
	aipuApi->CaptureFlow(optionFlow);
}


void UnmanagedAipu::SetIpCamera(LPCWSTR ip) {
	wstring lpcwstrToWstring(ip);
	string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());
	aipuApi->SetIpCamera(wStringToString);
}

void UnmanagedAipu::SetFaceConfidenceThresh(int value) {
	aipuApi->SetFaceConfidenceThresh(value);
}

void UnmanagedAipu::SetRefreshInterval(int value) {
	aipuApi->SetRefreshInterval(value);
}

void UnmanagedAipu::SetMinEyeDistance(int minDistance) {
	aipuApi->SetMinEyeDistance(minDistance);
}

void UnmanagedAipu::SetMaxEyeDistance(int maxDistance) {
	aipuApi->SetMaxEyeDistance(maxDistance);
}

void UnmanagedAipu::SetSequenceFps(int fps) {
	aipuApi->SetSequenceFps(fps);
}

void UnmanagedAipu::SetClient(int value) {
	aipuApi->SetClient(value);
}

void UnmanagedAipu::SetFlagFlow(bool flag) {
	aipuApi->SetFlagFlow(flag);
}

void UnmanagedAipu::Terminate() {
	aipuApi->Terminate();
}

void UnmanagedAipu::ReloadRecognitionFace() {
	aipuApi->ReloadRecognitionFace();
}

void UnmanagedAipu::SetConfigurationDatabase() {
	aipuApi->SetConfigurationDatabase();
}

void UnmanagedAipu::ShowWindow(int option) {
	aipuApi->ShowWindow(option);
}

void UnmanagedAipu::SetIsFinishLoadFiles(bool value) {
	aipuApi->SetIsFinishLoadFiles(value);
}

bool UnmanagedAipu::GetIsFinishLoadFiles() {
	return aipuApi->GetIsFinishLoadFiles();
}