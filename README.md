# string_view_split
Inline split function for std::string_view

# Example

```c++
FILE* file = fopen("somefile.txt", "rb");
if( file )
{
    struct stat st;
    if(stat("somefile.txt", &st) == 0)
    {
        std::vector<uint8_t> buffer(st.st_size);
        if( fread(buffer.data(), buffer.size(), 1, file) == 1 )
        {
            std::string_view strvw(buffer.data(), buffer.size());
            auto lines = string_view_split(strvw, "\n");
            for(auto line_view : lines)
            {
                printf("%.*s\n", static_cast<int>(line_view.size()), line_view.data()); 
            }
        }
    }
    if( fread
    fclose(file);
}

```
