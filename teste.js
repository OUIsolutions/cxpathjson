data(
    scope(
        incase(
            andequal(get("b","c",2),true),
            andequal(get("b","c",2),true),
            orequal((get("b","c",2),true))
        ),
        
        exec(
            ask_int("age","what its your age"),  
        )       

    ),    
    create_object("test","object"),
    set_val("test","a",20),

listage(
        $as("a"),
        $scope(
            $ask_int("age","what its your age"),
        )
    ),

    $create_action(
        $action_name("obter_contextacao"),
        $max_try(5),
        $delay("30m")
    )
)
