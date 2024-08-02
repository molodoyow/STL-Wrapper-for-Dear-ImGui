# Standard Template Library Wrapper for Dear ImGui Library
Dear ImGui - Bloat-free Graphical User interface for C++ with minimal dependencies
## API overview
```cpp
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

```
