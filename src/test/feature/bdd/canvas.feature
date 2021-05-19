Feature: Draw Canvas
Given canvas is enabled
| shapes |
| canvas |

  Scenario: canvas menu is enabled
    When programme is executed
    Then below menu are displayed
      | selector | description                                                   |
      | C        | Should create a new canvas CanvasPage of width w and height h |


  Scenario: Line menu works
    Given canvas shape exists
    And below menu are displayed
      | selector      | description                                                                                                                                                                          |
      | L x1 y1 x2 y2 | Should create a new line from (x1,y1) to (x2,y2). Currently only  horizontal or vertical lines are supported. Horizontal and vertical lines   will be drawn using the 'x' character. |
    When L option is chosen
    Then canvas shows below pattern
      | pattern                |
      | ---------------------- |
      |                        |
      | xxxxxx                 |
      |                        |
      |                        |
      | ---------------------- |
