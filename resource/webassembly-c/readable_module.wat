(module
  (type (;0;) (func (param i32 i32) (result i32)))
  (func (;0;) (type 0) (param i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    i32.const 4000
    i32.sub
    local.tee 1
    global.set 0
    i32.const 1000
    local.set 2
    local.get 1
    local.set 0
    loop  ;; label = @1
      local.get 0
      local.get 2
      i32.store
      local.get 0
      i32.const 16
      i32.add
      local.get 2
      i32.const 4
      i32.sub
      i32.store
      local.get 0
      i32.const 12
      i32.add
      local.get 2
      i32.const 3
      i32.sub
      i32.store
      local.get 0
      i32.const 8
      i32.add
      local.get 2
      i32.const 2
      i32.sub
      i32.store
      local.get 0
      i32.const 4
      i32.add
      local.get 2
      i32.const 1
      i32.sub
      i32.store
      local.get 0
      i32.const 20
      i32.add
      local.set 0
      local.get 2
      i32.const 5
      i32.sub
      local.tee 2
      br_if 0 (;@1;)
    end
    i32.const 999
    local.set 5
    loop  ;; label = @1
      local.get 5
      i32.const 1
      i32.and
      local.set 9
      local.get 1
      i32.load
      local.set 2
      block  ;; label = @2
        local.get 7
        i32.const 998
        i32.eq
        if  ;; label = @3
          i32.const 0
          local.set 4
          br 1 (;@2;)
        end
        local.get 5
        i32.const -2
        i32.and
        local.set 10
        i32.const 0
        local.set 4
        local.get 1
        local.set 0
        loop  ;; label = @3
          block  ;; label = @4
            local.get 0
            i32.const 4
            i32.add
            local.tee 8
            i32.load
            local.tee 3
            local.get 2
            i32.ge_s
            if  ;; label = @5
              local.get 3
              local.set 2
              br 1 (;@4;)
            end
            local.get 0
            local.get 3
            i32.store
            local.get 8
            local.get 2
            i32.store
          end
          local.get 4
          i32.const 2
          i32.add
          local.set 4
          block  ;; label = @4
            local.get 0
            i32.const 8
            i32.add
            local.tee 6
            i32.load
            local.tee 3
            local.get 2
            i32.ge_s
            if  ;; label = @5
              local.get 3
              local.set 2
              br 1 (;@4;)
            end
            local.get 0
            i32.const 8
            i32.add
            local.get 2
            i32.store
            local.get 8
            local.get 3
            i32.store
          end
          local.get 6
          local.set 0
          local.get 4
          local.get 10
          i32.ne
          br_if 0 (;@3;)
        end
      end
      block  ;; label = @2
        local.get 9
        i32.eqz
        br_if 0 (;@2;)
        local.get 2
        local.get 4
        i32.const 2
        i32.shl
        local.tee 0
        local.get 1
        i32.add
        i32.const 4
        i32.add
        local.tee 3
        i32.load
        local.tee 6
        i32.le_s
        br_if 0 (;@2;)
        local.get 3
        local.get 2
        i32.store
        local.get 0
        local.get 1
        i32.add
        local.get 6
        i32.store
      end
      local.get 5
      i32.const 1
      i32.sub
      local.set 5
      local.get 7
      i32.const 1
      i32.add
      local.tee 7
      i32.const 999
      i32.ne
      br_if 0 (;@1;)
    end
    local.get 1
    i32.const 4000
    i32.add
    global.set 0
    i32.const 0)
  (memory (;0;) 1)
  (global (;0;) (mut i32) (i32.const 5120))
  (export "memory" (memory 0))
  (export "main" (func 0)))
