#ifndef H_CUSTOM_IMGUI_STL
#define H_CUSTOM_IMGUI_STL

#include "../imgui.h"

#include <array>
#include <vector>
#include <string>
#include <tuple>
#include <map>

namespace ImGui::Custom
{	
	void Text(std::string_view label);
	void TextWrapped(std::string_view label);
	void TextColored(const ImVec4& col, std::string_view label);
	void TextDisabled(std::string_view label);
	void LabelText(std::string_view label, std::string_view format);
	void BulletText(std::string_view label);
	void SeparatorText(std::string_view label);
	  
	template<typename RandomAccessIterator, std::size_t element_count>
	bool Combo(std::string_view caption, RandomAccessIterator& current_iter, 
	    std::array<std::string_view, element_count>& elements, int height_in_items = 3, ImGuiComboFlags flags = 0);
	    
	template<typename Iterator>
	bool Combo(std::string_view caption, Iterator& current_iter, 
	    Iterator begin, Iterator end, int height_in_items = 3, ImGuiComboFlags flags = 0);
	    
	template<typename RandomAccessIterator, std::size_t element_count>
	bool ListBox(std::string_view caption, RandomAccessIterator& current_iter, 
	    std::array<std::string_view, element_count>& elements, const ImVec2& size = {});
	    
	template<typename Iterator>
	bool ListBox(std::string_view caption, Iterator& current_iter, 
		Iterator begin, Iterator end,  const ImVec2& size = {});
}

void ImGui::Custom::Text(std::string_view label)
{
	ImGui::Text(label.data());
}

void ImGui::Custom::TextWrapped(std::string_view label)
{
	ImGui::TextWrapped(label.data());
}

void ImGui::Custom::TextColored(const ImVec4& col, std::string_view label)
{
	ImGui::TextColored(col, label.data());
}

void ImGui::Custom::TextDisabled(std::string_view label)
{
	ImGui::TextDisabled(label.data());
}

void ImGui::Custom::LabelText(std::string_view label, std::string_view format)
{
	ImGui::LabelText(label.data(), format.data());
}

void ImGui::Custom::BulletText(std::string_view label)
{
	BulletText(label.data());
}

void ImGui::Custom::SeparatorText(std::string_view label)
{
	ImGui::SeparatorText(label.data());
}

template<typename RandomAccessIterator, std::size_t element_count>
bool ImGui::Custom::Combo(std::string_view caption, RandomAccessIterator& current_iter, 
	std::array<std::string_view, element_count>& elements, int height_in_items, ImGuiComboFlags flags)
{
	RandomAccessIterator begin = elements.begin();
	RandomAccessIterator end = elements.end();
	return Combo(caption, current_iter, begin, end, height_in_items, flags);  
}

template<typename Iterator>
bool ImGui::Custom::Combo(std::string_view caption, Iterator& current_iter, 
	Iterator begin, Iterator end, int height_in_items, ImGuiComboFlags flags)
{
	Iterator previous_iter = current_iter;
	std::string_view current_value = *current_iter;
	const char* preview_value = current_value.data();
 
	if (ImGui::BeginCombo(caption.data(), preview_value, flags))
	{
		for (auto it = begin; it != end; it++)
		{
			std::string_view value = *it;
			const bool is_selected = (current_iter == it);
			if (ImGui::Selectable(value.data(), is_selected))
				current_iter = it;

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	return previous_iter != current_iter; 
}

template<typename RandomAccessIterator, std::size_t element_count>
bool ImGui::Custom::ListBox(std::string_view caption, RandomAccessIterator& current_iter, 
	std::array<std::string_view, element_count>& elements, const ImVec2& size)
{
	auto begin = elements.begin();
	auto end = elements.end();
	return ListBox(caption, current_iter, begin, end, size);  
}

template<typename Iterator>
bool ImGui::Custom::ListBox(std::string_view caption, Iterator& current_iter, 
	Iterator begin, Iterator end, const ImVec2& size)
{
	auto previous_iter = current_iter;
	std::string_view current_value = *current_iter;
	const char* preview_value = current_value.data();
 
	if (ImGui::BeginListBox(caption.data(), size))
	{
		for (auto it = begin; it != end; it++)
		{
			std::string_view value = *it;
			const bool is_selected = (current_iter == it);
			if (ImGui::Selectable(value.data(), is_selected))
				current_iter = it;

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndListBox();
	}
	return previous_iter != current_iter; 
}

#endif
