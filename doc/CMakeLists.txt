add_subdirectory(kfile)
add_subdirectory(kspell)

install(FILES kdebug.html DESTINATION ${KDE1_HTMLDIR}/en/kdelibs)
add_custom_target(link_target ALL COMMAND ${CMAKE_COMMAND} -E create_symlink en default)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/default DESTINATION ${KDE1_HTMLDIR})
