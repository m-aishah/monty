char *my_strdup(const char *src)
{
    char *dest = malloc(strlen(src) + 1);
    if (dest == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return NULL;
    }
    strcpy(dest, src);
    return dest;
}