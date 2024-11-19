#pragma once
#using <Microsoft.VisualBasic.dll>

namespace NLaba10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(183, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(390, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Створити чергу цілих чисел. Знайти середнє арифметичне елементів черги.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Введіть розмір черги ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(524, 90);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Додати елементи";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(524, 131);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(171, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Видалити елменти";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(316, 202);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Обчислити";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(316, 90);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 5;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(168, 90);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(804, 487);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
private:
	System::Collections::Generic::Queue<int>^ myQueue1 = gcnew System::Collections::Generic::Queue<int>();
	bool isQueueInitialized = false;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Додавання елементів у чергу
	if (!isQueueInitialized) {
		isQueueInitialized = true;
	}

	// Отримуємо розмір черги з textBox1
	int size = Convert::ToInt32(textBox1->Text);
	if (myQueue1->Count < size) {
		// Введення елемента через InputBox
		String^ valueInput = Microsoft::VisualBasic::Interaction::InputBox("Введіть елемент черги:", "Додавання елементу", "0");

		if (valueInput == "") {
			return; // Якщо введення скасоване
		}
		int inputValue = Convert::ToInt32(valueInput);

		myQueue1->Enqueue(inputValue);
		listBox1->Items->Add(inputValue.ToString());
	}
	else {
		listBox1->Items->Add("Досягнуто ліміт чисел");
	}
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Видалення елементів із черги
	if (isQueueInitialized) {
		if (myQueue1->Count > 0) {
			myQueue1->Dequeue();
			listBox1->Items->Clear();
			for each (int value in myQueue1) {
				listBox1->Items->Add(value.ToString());
			}
		}
		else {
			listBox1->Items->Add("Черга порожня");
		}
	}
	else {
		listBox1->Items->Add("Черга ще не була ініціалізована");
	}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	// Обчислення середнього арифметичного
	if (isQueueInitialized && myQueue1->Count > 0) {
		int sum = 0;
		for each (int value in myQueue1) {
			sum += value;
		}
		double average = (double)sum / myQueue1->Count;
		MessageBox::Show("Середнє арифметичне: " + average.ToString("F2"));
	}
	else if (!isQueueInitialized) {
		MessageBox::Show("Черга ще не була ініціалізована");
	}
	else {
		MessageBox::Show("Черга порожня");
	}
}

	};
}
